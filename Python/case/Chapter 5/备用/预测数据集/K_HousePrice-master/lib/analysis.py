import pandas as pd
import numpy as np
from scipy import stats
import matplotlib
import matplotlib.pyplot as plt
import seaborn as sns
from collections import OrderedDict
import scipy.stats as stats
from math import ceil

import matplotlib.gridspec as gridspec

def pd_distribplot(Data, include=None, _Save=False) :
    if include == None :
        for col in Data.columns :
            n_NaN = Data[col].isna().any().sum()
            col_data = Data[col].dropna()
            ax0 = sns.distplot(col_data)
            var = np.var(col_data)
            mean = np.mean(col_data)
            ax0.set_title(col + '\n variance: {}, mean: {}'.format(var, mean) + '\nTotal_Elements: {} NaN elements: {}'.format(len(col_data.index), n_NaN))
            if _Save :
                fig1 = plt.gcf()
                fig1.savefig('vizu/distrib/{}_distrib.png'.format(col))
            plt.show()
    else :
        for col in include :
            ax = sns.distplot(Data[col])
            ax.set_title(col)
            if _Save :
                fig1 = plt.gcf()
                fig1.savefig('vizu/distrib/{}_distrib.png'.format(col))
            plt.show()


    plt.show()
    return 1

def corr_all(Pred, Data, alpha=0.05, disp=False):
#     Correl = {}
#     for i, col in enumerate(Data.columns) :
#         first_index = Data[col].first_valid_index()
#         type_col = type(Data[col][first_index])
#
#         if  type_col == str :
#             Correl[col] = corr_categorical(Pred, Data[col], alpha=alpha)
#         elif ( type_col == float) | (type_col == int) | (type_col == np.int64) | (type_col == np.float64):
#             Correl[col] = corr_Pearson(Pred, Data[col], alpha=alpha)
#         else :
#             print('WARNING : column {} has unknown type'.format(col))
#
#     checked_features = []
#     for key in Correl :
#         if Correl[key] == False :
#             if disp :
#                 print('{} is not significant'.format(key))
#             checked_features.append(key)
#
    return checked_features

def pd_corr_Pearson(Pred, Data_col):
    res = 0

    index = Data_col.index[Data_col.apply(np.isnan)]
    Data_col = Data_col.drop(index)
    Pred = Pred.drop(index)
    if Data_col.isna().any() :
        print('WARNING : Dealing with NaN values')
    Pearson = Pred.corrwith(Data_col, method='pearson')
    r_value = Pearson.T[0]
    p_value = 0

    return r_value, p_value

def corr_categorical(Pred, Data_col, alpha, _Gaussian=False) :
    res = 0

    Data_col.fillna(value='None', inplace=True)
    Tags = Data_col.unique()
    dic_tags = {}

    for tag in Tags :
        tag_index = Data_col.index[Data_col == tag].tolist()
        tag_prices = Pred.ix[tag_index].values
        dic_tags[tag] = tag_prices

    if _Gaussian : # Normally ditributed <--- ANOVA
        print('WIP : Anova test not implemented')
        # OW_ANOVA = stats.f_oneway(Data_col, Pred)
        return 0
    else : # Otherwise <--- Kruskal Wallis test
        tuple_arg = ([x for x in list(dic_tags.values())])
        kruskal_res = stats.kruskal(*tuple_arg)
        p_value, H_value = (kruskal_res.pvalue, kruskal_res.statistic)
        if p_value < alpha :
            res = 1
        else :
            res = 0

    return res

def corr_heatmap(Pred, Data, methods=('pearson', 'spearman', 'kendall'), _Save=True):
    full = pd.concat((Pred, Data), axis=1, sort=True)

    fig = plt.figure(num=None, figsize=(3, 7), dpi=95, facecolor='w')
    gs = gridspec.GridSpec(len(methods), 2, width_ratios=[14, 1], wspace=0.2, hspace=0.5)

    result = []
    for i, method in enumerate(methods) :
        res = full.corr(method=method)

        axes = plt.subplot(gs[i,0])
        pc = plt.pcolor(res, cmap='afmhot')
        axes.set_title(method)
        axes.set_xticks(np.arange(res.shape[1]) + 0.5)
        axes.set_yticks(np.arange(res.shape[0]) + 0.5)
        axes.set_xticklabels(list(res.columns), rotation=90, fontdict={'weight': 'normal','size': 4})
        axes.set_yticklabels(list(res.index), fontdict={'weight': 'normal','size': 4})

        axes = plt.subplot(gs[i,1])
        plt.colorbar(pc, cax=axes)

    if _Save :
        fig = plt.gcf()
        fig.savefig('vizu/CorrelHeatMap.png')

    plt.show()

    return 0

def missing_val_analysis(Pred, Data, zeroes=False, _Save=False) :
    full = pd.concat((Pred, Data), axis=1, sort=True)
    col_with_na = {}
    col_with_zeroes = {}

    for col in full.columns :
        if full[col].isna().any() :
            n = full[col].isna().sum(skipna=False)
            pct_col = float(n)/len(full[col])
            col_with_na[col] = pct_col
        elif full[col].eq(0).any().any() and zeroes == True :
            n = full[col].eq(0).sum(skipna=False)
            pct_col = float(n)/len(full[col])
            col_with_na[col] = pct_col
            col_with_zeroes[col] = pct_col*100


    ordered = OrderedDict(sorted(col_with_na.items(), key=lambda item:np.min(item[1])))
    cols = list(ordered.keys())
    pct_values = [x*100 for x in ordered.values()]

    pltte = sns.color_palette("coolwarm", len(col_with_na))
    ax = sns.barplot(cols, y=pct_values, palette=pltte)
    ax.set_title('Missing values (NaN)', fontdict={'weight': 'normal','size': 12})
    ax.set_xlabel('Column Labels', fontdict={'weight': 'normal','size': 12})
    ax.set_ylabel('missing values (in %)', fontdict={'weight': 'normal','size': 12})
    plt.xticks(rotation=70)
    if zeroes :
        ax.set_title('Missing Values (including 0 values)')
    else :
        ax.set_title('Missing Values (NaN only)')

    if _Save :
        fig = plt.gcf()
        if zeroes :
            fig.savefig('vizu/MissignValues_WZeroes.png')
        else :
            fig.savefig('vizu/MissignValues')


    plt.show()

    return col_with_na

def outlier_analysis(Data, Pred, include=None, trsh=0.99, _Save=False):
    indexes = []
    if include == None :
        iterable = Data.columns
    else :
        iterable = include

    for col in iterable :
        data = pd.concat((Pred, Data[col]), axis=1, sort=True)
        Pred_quant = Pred.quantile(trsh).values[0]
        Data_quant = Data[col].quantile(trsh)
        s1 = sns.jointplot(x=col, y=Pred.columns[0], data=data, kind='reg')
        s1.ax_joint.plot([0, Data[col].max()*1.1], [Pred_quant, Pred_quant], linewidth=2)
        s1.ax_joint.plot([Data_quant, Data_quant], [0, Pred.max()*1.1], linewidth=2)
        s1.set_axis_labels(xlabel=col, ylabel=Pred.columns[0])
        s1.annotate(stats.pearsonr)

        plt.subplots_adjust(top=0.9)
        s1.fig.suptitle('{} Outlier Analysis \n quantile at {}'.format(col, trsh))

        pear_r = stats.pearsonr(data.iloc[:,0], data.iloc[:,1])[0]
        if pear_r > 0.5 :
            id_above = Data.loc[Data[col] > Data_quant].index
            coresp = Pred.ix[id_above]
            id_outlier = coresp.loc[Pred.iloc[:,0] < Pred_quant].index
            print(id_outlier)

        if _Save :
            fig = plt.gcf()
            fig.savefig('vizu/outlier/{}_outlierAnalysis.png'.format(col))

        plt.show()

    return indexes

def skew_analysis(Data, trsh_line=0.5, order='asc', _Save=False) :
    skew_res = Data.skew()
    if order == 'asc' :
        skew_res.sort_values(ascending=True, inplace=True)
    elif order == 'desc':
        skew_res.sort_values(ascending=False, inplace=True)

    # br_plt = plt.bar(Data.columns, skew_res, align='center')
    ax = sns.barplot(skew_res.index, y=skew_res.values, palette="Blues_d")
    ax.axhline(y=trsh_line, linewidth=1, color='k', dashes=[30, 5, 10, 5], alpha=0.5)
    ax.axhline(y=-trsh_line, linewidth=1, color='k', dashes=[30, 5, 10, 5], alpha=0.5)
    plt.xticks(rotation=90)
    ax.set_title('Skewness analysis treshold: {}'.format(trsh_line))

    if _Save :
        fig = plt.gcf()
        fig.savefig('vizu/ContinuousData_skewness')

    # df.index[df['BoolCol'] == True].tolist()
    plt.show()
    skewed = [index for index in skew_res.index if abs(skew_res[index])>trsh_line]


    return skewed
