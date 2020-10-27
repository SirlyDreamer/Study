"""
问题描述：Titanic生存预测


#**输入:性别、年龄、船票等级等
#**输出：生存/死亡
https://github.com/mohitksharma/titanic_survival
"""


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sklearn
from sklearn.preprocessing import LabelEncoder, OneHotEncoder
#from sklearn.cross_validation import train_test_split
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.metrics import make_scorer, accuracy_score


#----Step 0: 读入数据------------------
#（1）读入原始数据
df      = pd.read_csv("Dataset/train.csv");df.dropna(inplace=True)
X_train = df.iloc[:, [2,4,5,6,7,9]]
y_train = df.iloc[:, 1]

df_test = pd.read_csv("Dataset/test.csv");df_test.dropna(inplace=True)
X_test  = df_test.iloc[:, [1,3,4,5,6,8]]


#（2）数据预处理----------------------#Handling categorical value
le = LabelEncoder()
X_train.iloc[:, 1] = le.fit_transform(X_train.iloc[:, 1])
ohe = OneHotEncoder(categorical_features=[1])
X_train = ohe.fit_transform(X_train).toarray()

le = LabelEncoder()
X_test.iloc[:, 1] = le.fit_transform(X_test.iloc[:, 1])
ohe = OneHotEncoder(categorical_features=[1])
X_test = ohe.fit_transform(X_test).toarray()
#-------------------------------------------


#----Step 1: 预测模型训练--------------------
#training and test spliting in train.csv tftr is test from train
X_train, X_tftr, y_train, y_tftr = train_test_split(X_train, y_train)

#Training on SVM
regressor = SVC(kernel='rbf')
regressor.fit(X_train,y_train)
y_pred    = regressor.predict(X_tftr)
print(accuracy_score(y_tftr, y_pred)) #Accuracy with SVM 67.39
#-------------------------------------------


#----Step 2: 预测---------------------------
#final predicting using test.csv
y_test = regressor.predict(X_test)
#-------------------------------------------