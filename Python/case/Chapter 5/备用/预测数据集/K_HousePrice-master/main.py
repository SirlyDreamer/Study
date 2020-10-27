import warnings
warnings.filterwarnings("ignore")

from lib.pd_load_data import *
from lib.analysis import *
from lib.utils import *
from lib.Network_setup import *
from lib.evaluate_models import *
from lib.plot_results import *
import PltOptions

import matplotlib.pyplot as plt
import statsmodels.api as sm
import numpy as np


## # TEMP:
from sklearn.linear_model import Lasso, ElasticNet, Ridge
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import RobustScaler
from sklearn.ensemble import RandomForestRegressor
from sklearn.kernel_ridge import KernelRidge
from sklearn.svm import SVR
from sklearn.ensemble import GradientBoostingRegressor
from keras.wrappers.scikit_learn import KerasClassifier
import lightgbm as lgb

numeric_dtypes = ('int16', 'int32', 'int64', 'float16', 'float32', 'float64')
col_num2binary = ('Fireplaces', 'WoodDeckSF', 'EnclosedPorch', 'PoolArea',
                  '3SsnPorch', 'LowQualFinSF', 'MiscVal', 'ScreenPorch', 'BsmtFullBath',
                  'BsmtHalfBath', 'FullBath', 'HalfBath', 'BedroomAbvGr', 'KitchenAbvGr')
high_paerson = ('1stFlrSF', 'GarageArea', 'GrLivArea', 'TotalBsmtSF')
if __name__ == '__main__' :
    # load the Data and output
    Data = load_data('data/train.csv', index_col='Id')
    Target = pd.DataFrame(Data[u'SalePrice'], index=Data.index)
    Data = Data.drop(columns=[u'SalePrice'])
    Data.drop(['Utilities', 'Street', 'PoolQC',], axis=1)
    Data['haspool'] = Data['PoolArea'].apply(lambda x: 1 if x > 0 else 0)

    ###############################Feature Engineering#############################


    # Apply Data Transformation continuous values
    continuous_df = Data.select_dtypes(include=numeric_dtypes)
    # outlier_ID = outlier_analysis(continuous_df, Target, include=high_paerson, trsh=0.995, _Save=False)
    # for x in outlier_ID :
    #     print(x)
    """
    1stFlrSF    : Int64Index([497, 524, 530, 1025, 1045, 1299, 1374], dtype='int64', name=u'Id')
    GarageArea  : Int64Index([179, 582, 665, 826, 1062, 1191, 1299, 1418], dtype='int64', name=u'Id')
    GrLivArea   : Int64Index([186, 305, 524, 1269, 1299], dtype='int64', name=u'Id')
    TotalBsmtSF :Int64Index([333, 497, 524, 1045, 1299, 1374], dtype='int64', name=u'Id')
    --> Shared : [524, 1299, 1045, 1374]
    """

    continuous_df = df_toBinary(continuous_df, include=col_num2binary)
    continuous_df = pd_fixskew(continuous_df,  exclude=col_num2binary) # also standarzing the values
    for col in continuous_df.columns :
        Data[col] = continuous_df[col]
    Target_rs, transformer = pd_fixskew(Target, return_lambda=True)

    # Deal With Caterorical Data (One Hot encoding)
    categorical_df = Data.select_dtypes(include=(object))
    categorical_df.fillna(value='None')
    Ohe_df = pd_one_hot_encoder(categorical_df)
    Data.drop(columns=categorical_df.columns, inplace=True)
    Raw_input = pd.concat((Data, Ohe_df), axis='columns')
    for col in Raw_input.columns :
        if Raw_input[col].isna().any():
            Raw_input[col] = Raw_input[col].fillna(value=0)

    Raw_input.drop([524, 1299, 1045, 1374], inplace=True)
    Target_rs.drop([524, 1299, 1045, 1374], inplace=True)


    ###############################Evaluate Models#############################
    folds = 10
    # Random Forest
    Rdm_forest = RandomForestRegressor(n_estimators=48, criterion='mse', max_depth=None,
                                       min_samples_split=3, min_samples_leaf=15, min_weight_fraction_leaf=0.0,
                                       max_features='auto', max_leaf_nodes=None, min_impurity_decrease=0.0, min_impurity_split=None,
                                       bootstrap=True, oob_score=False, n_jobs=None, random_state=10, verbose=0, warm_start=True)
    score =  rmsle_cv(Rdm_forest, Raw_input, Target_rs, n_folds=folds)
    print('Random Foreset score : {} ({})'.format(score.mean(), score.std()))



    # Lasso model
    lasso = make_pipeline(RobustScaler(), Lasso(alpha=0.0005, random_state=1))
    score = rmsle_cv(lasso, Raw_input, Target_rs, n_folds=folds)
    print('lasso score : {} ({})'.format(score.mean(), score.std()))

    # ElasticNet
    ENet = make_pipeline(RobustScaler(), ElasticNet(alpha=0.0005, l1_ratio=.9, random_state=3))
    score = rmsle_cv(ENet, Raw_input, Target_rs, n_folds=folds)
    print('ENet score : {} ({})'.format(score.mean(), score.std()))

    # SVR
    svr = make_pipeline(RobustScaler(), SVR(C= 20, epsilon= 0.008, gamma=0.0003,))
    score = rmsle_cv(svr, Raw_input, Target_rs, n_folds=folds)
    print('SVR score : {} ({})'.format(score.mean(), score.std()))

    # Ridge
    alphas_alt = [14.5, 14.6, 14.7, 14.8, 14.9, 15, 15.1, 15.2, 15.3, 15.4, 15.5]
    ridge = make_pipeline(RobustScaler(), RidgeCV(alphas=alphas_alt))
    score = rmsle_cv(ridge, Raw_input, Target_rs, n_folds=folds)
    print('Ridge score : {} ({})'.format(score.mean(), score.std()))

    # KernelRidge
    KRR = KernelRidge(alpha=0.6, kernel='polynomial', degree=2, coef0=2.5)
    score = rmsle_cv(KRR, Raw_input, Target_rs, n_folds=folds)
    print('KernelRidge score : {} ({})'.format(score.mean(), score.std()))

    # GradBoost
    GBoost = GradientBoostingRegressor(n_estimators=3000, learning_rate=0.05,
                                   max_depth=4, max_features='sqrt',
                                   min_samples_leaf=15, min_samples_split=10,
                                   loss='huber', random_state =5)
    score = rmsle_cv(GBoost, Raw_input, Target_rs, n_folds=folds)
    print('GradBoost score : {} ({})'.format(score.mean(), score.std()))

    # LGBMRegressor
    lgb_model = lgb.LGBMRegressor(objective='regression',num_leaves=5,
                              learning_rate=0.05, n_estimators=720,
                              max_bin = 55, bagging_fraction = 0.8,
                              bagging_freq = 5, feature_fraction = 0.2319,
                              feature_fraction_seed=9, bagging_seed=9,
                              min_data_in_leaf =6, min_sum_hessian_in_leaf = 11)
    score = rmsle_cv(lgb_model, Raw_input, Target_rs, n_folds=folds)
    print('LGBMRegressor score : {} ({})'.format(score.mean(), score.std()))


    # NN model
    # neural_network = KerasClassifier(build_fn=load_NN,
    #                              epochs=200,
    #                              batch_size=100,
    #                              verbose=0)
    #
    # # NN_model = load_NN(input_shape=Raw_input.shape[0], Output_shape=1, layers=5, n_units=100)
    # score = rmsle_cv(neural_network, Raw_input, Target_rs, n_folds=5)
    # print('NN score : {} ({})'.format(score.mean(), score.std()))
