
from sklearn import preprocessing
from sklearn.model_selection import KFold
from sklearn.metrics import mean_squared_error
from sklearn.linear_model import ElasticNetCV, LassoCV, RidgeCV
from sklearn.preprocessing import power_transform, PowerTransformer, RobustScaler
from sklearn.ensemble import IsolationForest

import pandas as pd
import numpy as np
from scipy.stats import skew, boxcox
from scipy.special import inv_boxcox

from math import floor, sqrt


import sys

def pd_split(Df, split=0.1) :
    index_l = len(Df.index)
    slice = int(floor(len(Df.index)*0.1))
    Train = Df.iloc[slice:,:]
    Test = Df.iloc[:slice,:]

    return Train, Test

def pd_normalize(Data) :
    x = Data.values
    x = np.nan_to_num(x, copy=True)
    scaler = preprocessing.MinMaxScaler()
    x_n = scaler.fit_transform(x)
    data_n = pd.DataFrame(x_n, index=Data.index, columns=Data.columns)
    return data_n, scaler

def pd_robustscale(Data) :
    x = Data.values
    scaler = RobustScaler()
    x_rs = scaler.fit_transform(x)
    data_rs = pd.DataFrame(x_rs, index=Data.index, columns=Data.columns)
    return data_rs, scaler

def pd_one_hot_encoder(Data) :
    cols = Data.columns
    Ohe_df = pd.DataFrame(index=Data.index, columns=None)
    for col in Data.columns :
        one_hot = pd.get_dummies(Data[col], prefix=col)
        Ohe_df = pd.concat((Ohe_df, one_hot), axis='columns')

    return Ohe_df

def measure_rmse(actual, predicted):
    return sqrt(mean_squared_error(actual, predicted))

def pd_log1p(Data) :
    return np.log1p(Data)

def pd_expm1(Data) :
    return np.expm1(Data)

def pd_boxcox(Data, rtrn_lambdas=False) :
    BC_cols = np.empty(Data.shape)
    lambdas = []
    for i, col in enumerate(Data.columns) :
        bc_col = boxcox(Data[col])
        BC_cols[:,i] = bc_col[0]
        lambdas.append(bc_col[1])

    BC_Data = pd.DataFrame(BC_cols, index=Data.index, columns=Data.columns)

    if rtrn_lambdas :
        return BC_Data, lambdas
    else :
        return BC_Data

def pd_invboxcox(Data, lambdas) :
    Inv_BC_cols = np.empty(Data.shape)
    for i, col in enumerate(Data.columns):
        inv_bc_col = inv_boxcox(Data[col], lambdas[i])
        Inv_BC_cols[:,i] = inv_bc_col

    Inv_BC_Data = pd.DataFrame(Inv_BC_cols, index=Data.index, columns=Data.columns)
    return Inv_BC_Data

def pd_fixskew(Data, tresh=0.5, mthd='box-cox', exclude=[], return_lambda=False):
    """
    if data contains zero the boxcox is applied with shift of epsilon
    """
    skew_res = Data.skew()
    f_cols = np.empty(shape=Data.shape)
    transformer = []
    for i, col in enumerate(Data.columns) :
        if col in exclude :
            f_cols[:,i] = Data[col]
        else :
            array_col = np.reshape(Data[col].values, newshape=(len(Data[col]), 1))
            try :
                trnsfm = PowerTransformer(method=mthd, standardize=True)
                f_col = trnsfm.fit_transform(array_col)
                f_cols[:,i] = np.reshape(f_col, newshape=(len(Data[col],)))
                transformer.append(trnsfm)
            except :
                print('WARNING : {} failed on {} passing to yeo-johnson'.format(mthd, col))
                trnsfm = PowerTransformer(method='yeo-johnson', standardize=True)
                f_col = trnsfm.fit_transform(array_col)
                f_cols[:,i] = np.reshape(f_col, newshape=(len(Data[col],)))
                transformer.append(trnsfm)

    Data_skewFixed = pd.DataFrame(f_cols, index=Data.index, columns=Data.columns)
    if return_lambda :
        return Data_skewFixed, transformer
    else :
        return Data_skewFixed

def df_toBinary(df, include=None):
    Data_2B = df
    if include :
        for col in include :
            Data_2B[col] = (df[col] > 0).astype(int)
    else :
        print('WARNING : changing all to binary')

    return Data_2B

# def pd_outlier_detection(Data, Pred, include=None):
#     ids = []
#     if include :
#         for col_name in include :
#             data_col = np.reshape(np.array(Data.loc[:,include]), newshape=(len(Data[col_name]), len(include)))
#             pred_col = np.reshape(np.array(Pred.values), newshape=(len(Data[col_name]), 1))
#             pred_tool = IsolationForest(n_estimators=100, max_samples='auto', contamination=0.1,
#             max_features=1.0, bootstrap=False, n_jobs=None, behaviour='old',
#             random_state=42, verbose=0)
#             labels = pred_tool.fit_predict(data_col, pred_col)
#             indexs = np.where(labels == -1)
#             print(indexs)
#
#     else :
#         print('WARNING : The entire Dataframe was passed')
#
#
#     return ids
