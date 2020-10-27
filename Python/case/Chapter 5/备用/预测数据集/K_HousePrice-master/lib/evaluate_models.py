from sklearn.model_selection import KFold, cross_val_score
import numpy as np


def evaluate_OLS():
    print('evaluate_OLS : WIP')
    return 0

def rmsle_cv(model, train, Target, n_folds=5):
    kf = KFold(n_folds, shuffle=True, random_state=42).get_n_splits(train.values)
    rmse= np.sqrt(-cross_val_score(model, train.values, Target.values, scoring="neg_mean_squared_error", cv =kf))
    return(rmse)
