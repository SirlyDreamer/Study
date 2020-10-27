# -*- coding: utf-8 -*-
"""
问题描述：一个人的学习成绩，在一定程度上受到学习时长的影响，
本案例代码中假定学习时长与学习成绩大致符合线性关系。


#**输入:学习时长(小时)
#**输出：成绩（满分100分）
#**说明：一元线性回归，需进一步计算预测误差
"""


#——————————————————————————————————————————————————————————————————————————————————————
#梯度下降
def Optimization(x,y,theta,learning_rate):
    for i in range(iter):
        theta = Updata(x,y,theta,learning_rate)
    return theta
 
def Updata(x,y,theta,learning_rate):
    m = len(x)
    sum = 0.0
    sum1 = 0.0
    alpha = learning_rate
    h = 0
    for i in range(m):
        h = theta[0] + theta[1] * x[i]
        sum += (h - y[i])
        sum1 += (h - y[i]) * x[i]
    theta[0] -= alpha * sum / m 
    theta[1] -= alpha * sum1 / m 
    return theta
#——————————————————————————————————————————————————————————————————————————————————————


import copy
import numpy as np
from sklearn import linear_model
from matplotlib import style
import matplotlib.pyplot as plt


#----Step 0: 训练集和测试集------------------
x_train = [2.5, 5.1, 3.2, 8.5, 3.5,4.7,11.5,8.7,6.8,9.3,10.7,8,7.5,6,10.1] #学习时长
y_train = [21,47,27,75,30,41,100,78,60,83,93,69,64,54,91]                  #成绩
x_test  = [4.1,8.3,6.4]#y_test  = [35,72,58]
y_pred  = []
#-------------------------------------------


#----Step 1: 预测模型训练--------------------
learning_rate = 0.001   #数据初始化
theta         = [0,0]
iter          = 1000
theta         = Optimization(x_train,y_train,theta,learning_rate)
#-------------------------------------------


#----Step 2: 预测---------------------------
for item in x_test:
    y_pred.append(theta[0] + item * theta[1])
#-------------------------------------------


#----Step 3: 预测可视化---------------------- 
b             = np.arange(0,50)
c             = theta[0] + b * theta[1]

plt.figure(figsize=(15,15))
#plt.title('结果',fontsize=40);#plt.savefig("结果.jpg")
plt.scatter(x_train,y_train,s=200,c='g',marker='o')
plt.scatter(x_test,y_pred,s=200,c='r',marker='o')
plt.plot(b,c)
plt.xticks(fontsize=40);plt.yticks(fontsize=40)
plt.ylim((0,100));plt.xlim((0,11))
plt.xlabel('x',fontsize=40);plt.ylabel('y',fontsize=40)

#-------------------------------------------
