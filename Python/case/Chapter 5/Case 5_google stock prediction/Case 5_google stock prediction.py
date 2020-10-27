# -*- coding: utf-8 -*-
"""
https://www.cnblogs.com/developerdaily/p/8440622.html
@author: Liang

#**** N_train = 2711;         训练集---->用2711天     的4个特征,训练预测模型，即：用第X天的数据，预测第X+35天的股票价格label'(i.e.'Adj. Close'),
#**** N_test  = 678 ;         训练集---->用 678天     的4个特征,计算预测模型的精度  
#**** N_pred  = 35   (N*1%)   预测集---->用3390-3424天的4个特征,预测股票第3425-3459天的股票价格
                                     i.e.用“2018-2-6 ~ 2018-3-27”的4个特征,预测股票“2018-3-28 ~ 2018-5-1”的股票价格
#**** 总数NN = N_train + N_test + N_pred = 3424
#****     N1 = N_train + N_test          = 3389;其中N_train = N1*0.8
                                                    N_test  = N1*0.2

"""


import math,sklearn,datetime,time#import quandl
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import style
from scipy import stats
from sklearn import preprocessing, model_selection, svm
from sklearn.linear_model import LinearRegression
from sklearn.metrics import explained_variance_score,mean_absolute_error,r2_score,mean_squared_error,median_absolute_error


#----Step 0: 读入数据-------------------------------
#(0.1)load data
df_raw       = pd.read_csv('Raw Data/raw_data.csv')  #df = quandl.get('WIKI/GOOGL')
print(df_raw.head)
NN           = len(df_raw)

#(0.2)定义预测列变量，它存放研究对象的标签名
forecast_col = 'Adj. Close'
forecast_out = int(math.ceil(0.01*len(df_raw)))  #定义预测天数，这里设置为所有数据量长度的1%，i.e.35天

#(0.3)本预测模型，只用到原始数据df_raw中下面的几个字段
df           = df_raw[['Date','Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume']]
#---------------------------------------------------


#----Step 1: 新特征计算和最终特征选择-----------------
#(1.1)构造两个新的列
#***(1.i) HL_PCT为股票最高价与最低价的变化百分比
df['HL_PCT']     = (df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
#***(1.ii)PCT_change为股票收盘价与开盘价的变化百分比
df['PCT_change'] = (df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open']  * 100.0

#(1.2)下面为真正用到的特征字段
s_header = ['Date','Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume']
df       = df[s_header]
#---------------------------------------------------


#----Step 2: 数据预处理-----------------
#(2.1)缺省值处理
#***因为scikit-learn并不会处理空数据，需要把为空的数据都设置为一个比较难出现的值，这里取-9999，
df.fillna(-99999, inplace=True)

#(2.2)预测值。用label代表该字段，是预测结果
#***通过让与Adj. Close列的数据往前移动1%行来表示
df['label'] = df[forecast_col].shift(-forecast_out)   #35天后预测值


#(2.3)标准化
X = np.array(df.drop(['label'], 1))
X[:,1:] = preprocessing.scale(X[:,1:])  #标准化

#(2.4)预测值。上面生成label列时留下的最后1%行的数据，这些行并没有label数据，因此我们可以拿他们作为预测时用到的输入数据
#***(2.4.i)最后生成真正在模型中使用的数据X和y和预测时用到的数据数据X_lately
X_lately = X[-forecast_out:]
X = X[:-forecast_out]

df.dropna(inplace=True)
y = np.array(df['label'])# 抛弃label列中为空的那些行

#y = preprocessing.scale(y)

#---------------------------------------------------


#----Step 3: 训练集和测试集划分----------------------
#(3.1)开始前，先X和y把数据分成两部分，一部分用来训练，一部分用来测试
X_train, X_test, y_train, y_test = model_selection.train_test_split(X, y, test_size=0.2, random_state=42)
N_train = len(X_train)
N_test  = len(X_test)
N1      = N_train+N_test 

#(3.2)输出训练集，Data_train
D_train         = pd.DataFrame(X_train);
D_train.columns = s_header
D_train['label']= y_train;
D_train         = D_train.sort_values(by="Date" , ascending=True) #by指定列 ascending
D_train.to_csv('Processed Results/D_train.csv')
#---------------------------------------------------


#----Step 4: 预测模型--------------------------------
#(4.1)生成scikit-learn的线性回归对象
clf = LinearRegression(normalize=True,n_jobs=-1)

#(4.2)开始训练
clf.fit(X_train[:,1:], y_train)

#(4.3)用测试数据评估准确性
train_score    = clf.score(X_train[:,1:], y_train)
test_score     = clf.score(X_test[:,1:], y_test)
yy             = clf.predict(X_test[:,1:])

#(4.4)输出测试集预测结果，Data_test
D_test            = pd.DataFrame(X_test) 
D_test.columns    = s_header                           
D_test['label']   = y_test 
D_test['Forecast']= yy  
D_test            = D_test.sort_values(by="Date" , ascending=True) #by指定列 ascending
D_test.to_csv('Processed Results/D_test.csv')

#(4.5)误差计算
r2             = r2_score(y_test,yy)
mse            = mean_squared_error(y_test,yy)
median_ae      = median_absolute_error(y_test,yy)
mean_ae        = mean_absolute_error(y_test,yy)
pearson_pr     = stats.pearsonr(y_test,yy)

print("_________________________________________________________________________")
print("参数为            :        %.4f,%.4f,%.4f,%.4f"                                         %(clf.coef_[0],clf.coef_[1],clf.coef_[2],clf.coef_[3])) 
print("截距为            :        %.4f"                                                        %clf.intercept_)
print("Training set score:        %.4f"                                                        %train_score)
print("Test set score    :        %.4f"                                                        %test_score) 
print("r2_score:                  %.4f------>相关系数:0.2-0.4弱;0.4-0.6中等;0.6-0.8强;0.8-1极强"%r2)   
print("mean_squared_error:        %.4f"                                                        %mse)
print("median_absolute_error:     %.4f"                                                        %median_ae)
print("mean_absolute_error:       %.4f"                                                        %mean_ae)
print("pearson correlation:       %.4f,%.4f"                                                   %pearson_pr)
print("_________________________________________________________________________")     
#---------------------------------------------------


#----Step 5: 预测集，预测----------------------------
#(5.1)进行预测
forecast_set          = clf.predict(X_lately[:,1:])

#(5.2)预测结果输出
D_predict             = pd.DataFrame(X_lately) 
D_predict.columns     = s_header
D_predict['Forecast'] = forecast_set#.tolist()
pd.DataFrame(D_predict).to_csv('Processed Results/D_predict.csv')
#------------------------------------------------


#----Step 6: 已知股票价格+预测结果可视化----------
#(6.1)日期格式转换
one_day        = 86400     #Unix时间戳
last_date      = df_raw.iloc[-1].Date    # 取df_raw最后一行的时间索引,i.e.raw data最后一天的日期
last_unix      = time.mktime(time.strptime(last_date,'%Y-%m-%d'))
next_unix      = last_unix + one_day

#(6.2)预测结果按日期排列
#***遍历预测结果，用它往Data_plot追加行
D_plot               = df_raw['Date']
D_plot               = pd.DataFrame(D_plot) #***这些行除了Forecast字段，其他都设为np.nan
D_plot['Adj. Close'] = df_raw['Adj. Close']
D_plot['Forecast']   = np.nan                  # 在df中新建Forecast列，用于存放预测结果的数据
kk                   = NN-1
for i in forecast_set:
    kk               = kk+1
    next_date        = datetime.datetime.fromtimestamp(next_unix)
    next_unix       += one_day
    arr              = np.array([next_date,np.nan,i])
    ss               = pd.DataFrame({'Date'      :next_date.strftime('%Y-%m-%d'),
                                     'Adj. Close':np.nan,
                                     'Forecast'  :i},index=[1])
    D_plot           = D_plot.append(ss,ignore_index=True)#   
    
D_plot.to_csv('Processed Results/D_plot.csv')
#(6.3)开始绘图time_now = int(time.time())
fig = plt.figure()
style.use('ggplot')       
D_plot['Adj. Close'].plot()
D_plot['Forecast'].plot()
ax = fig.add_subplot(1, 1, 1)
plt.xlim(-200,3650)
ax.set_xticklabels(['','2004.8','2006.8','2008.8','2010.8','2012.7','2014.7','2016.7','2018.7'], rotation=30, fontsize='small')
plt.legend(loc=4)
plt.xlabel('Date')
plt.ylabel('Price')
plt.show()
#---------------------------------------------------


