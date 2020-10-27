# -*- coding: utf-8 -*-
"""
https://www.cnblogs.com/developerdaily/p/8440622.html@author: Liang
#**** N=3424
#**** train:   2711
#**** test :   678
#**** pred :   35   (N*1%）
"""


import math
import numpy as np
import quandl
import pandas as pd
import datetime
import matplotlib.pyplot as plt
import sklearn
import time
from sklearn import preprocessing, model_selection, svm
from sklearn.linear_model import LinearRegression
from matplotlib import style


#----Step 0: 读入数据-------------------------------
#(1)load data
df0=pd.read_csv('Dataset/test.csv')  #df = quandl.get('WIKI/GOOGL')
print(df0.head)

# 定义预测列变量，它存放研究对象的标签名
forecast_col = 'Adj. Close'
# 定义预测天数，这里设置为所有数据量长度的1%
forecast_out = int(math.ceil(0.01*len(df0)))
# 只用到df中下面的几个字段
df = df0[['Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume']]
#---------------------------------------------------


#----Step 1: 新特征计算和最终特征选择-----------------
# 构造两个新的列
# HL_PCT为股票最高价与最低价的变化百分比
df['HL_PCT'] = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
# PCT_change为股票收盘价与开盘价的变化百分比
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0

# 下面为真正用到的特征字段
df = df[['Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume']]
# 因为scikit-learn并不会处理空数据，需要把为空的数据都设置为一个比较难出现的值，这里取-9999，
df.fillna(-99999, inplace=True)
# 用label代表该字段，是预测结果
# 通过让与Adj. Close列的数据往前移动1%行来表示
df['label'] = df[forecast_col].shift(-forecast_out)

# 最后生成真正在模型中使用的数据X和y和预测时用到的数据数据X_lately
X = np.array(df.drop(['label'], 1))
# TODO 此处尚有疑问
X = preprocessing.scale(X)
# 上面生成label列时留下的最后1%行的数据，这些行并没有label数据，因此我们可以拿他们作为预测时用到的输入数据
X_lately = X[-forecast_out:]
X = X[:-forecast_out]
# 抛弃label列中为空的那些行
df.dropna(inplace=True)
y = np.array(df['label'])
#---------------------------------------------------


#----Step 2: 预测模型--------------------------------
# scikit-learn从0.2版本开始废弃cross_validation，改用model_selection
# 开始前，先X和y把数据分成两部分，一部分用来训练，一部分用来测试
X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y, test_size=0.2)

# 生成scikit-learn的线性回归对象
clf = LinearRegression(n_jobs=-1)
# 开始训练
clf.fit(X_train, y_train)
# 用测试数据评估准确性
accuracy = clf.score(X_test, y_test) 
#---------------------------------------------------


#----Step 3: 预测-----------------------------------
# 进行预测
forecast_set = clf.predict(X_lately)
#print(forecast_set, accuracy)
print(accuracy)
#---------------------------------------------------


#----Step 4: 画图-----------------------------------
# 修改matplotlib样式
style.use('ggplot')

one_day = 86400
# 在df中新建Forecast列，用于存放预测结果的数据
df['Forecast'] = np.nan
# 取df最后一行的时间索引
last_date = df0.iloc[-1].DateTime
last_unix = time.mktime(time.strptime(last_date,'%Y-%m-%d'))#last_date.Timestamp()
next_unix = last_unix + one_day

# 遍历预测结果，用它往df追加行
# 这些行除了Forecast字段，其他都设为np.nan
kk_1=0
kk_2=len(y_train)+ len(y_test)-1#N_rows
for i in forecast_set:
    kk_1=kk_1+1
    kk_2=kk_2+1
    next_date = datetime.datetime.fromtimestamp(next_unix)
    next_unix += one_day
    df.loc[kk_2] =[np.nan for _ in range(len(df.columns) - 1)] + [i] 
    #print(i)    
df.to_csv('Dataset/result.csv')

# 开始绘图               
df['Adj. Close'].plot()
df['Forecast'].plot()
plt.legend(loc=4)
plt.xlabel('Date')
plt.ylabel('Price')
plt.show()
#---------------------------------------------------

