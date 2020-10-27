'''
#Demo:  推荐未尝过的菜肴 ！！
本demo相关数据和代码说明，可参考：
       Peter Harrington著;李锐等译。机器学习实战[M], P262.人民邮电出版社，2013年第1版
该书PDF已上传到云课堂                             
''' 

from numpy import *
from numpy import linalg as la

#_______________________________________________________________________________________________
####(1)相似度:ecludSim,cosSim,pearsSim   ####################
def ecludSim(inA,inB):                   #欧式距离
    return(1.0/(1.0 + la.norm(inA - inB)))

def pearsSim(inA,inB):                   #皮尔逊相关系数
    if len(inA) < 3 : return 1.0
    return(0.5+0.5*corrcoef(inA, inB, rowvar = 0)[0][1])

def cosSim(inA,inB):                     #余弦相似度
    num = float(inA.T*inB)
    denom = la.norm(inA)*la.norm(inB)
    return(0.5+0.5*(num/denom))
################################################################


####(2)搜索引擎  ：standEst,svdEst   ############################
def standEst(dataMat, user, simMeas, item):
    n = shape(dataMat)[1]
    simTotal = 0.0; ratSimTotal = 0.0
    for j in range(n):
        userRating = dataMat[user,j]
        if userRating == 0: continue
        overLap = nonzero(logical_and(dataMat[:,item].A>0, \
                                      dataMat[:,j].A>0))[0]  #寻找两个用户都评级的物品
        if len(overLap) == 0: similarity = 0
        else: similarity = simMeas(dataMat[overLap,item], \
                                   dataMat[overLap,j])       
        print('the %d and %d similarity is: %f' % (item, j, similarity))
        simTotal += similarity
        ratSimTotal += similarity * userRating   
        print(userRating)
    if simTotal == 0: 
        return(0)
    else: 
        return(ratSimTotal/simTotal)
    
def svdEst(dataMat, user, simMeas, item):
    n = shape(dataMat)[1]
    simTotal = 0.0; ratSimTotal = 0.0
    U,Sigma,VT = la.svd(dataMat)
    Sig4 = mat(eye(4)*Sigma[:4])                 #arrange Sig4 into a diagonal matrix   #建立对角矩阵
    xformedItems = dataMat.T * U[:,:4] * Sig4.I  #create transformed items              #构建转换后的物品
    for j in range(n):
        userRating = dataMat[user,j]
        if userRating == 0 or j==item: continue
        similarity = simMeas(xformedItems[item,:].T,\
                             xformedItems[j,:].T)
        print('the %d and %d similarity is: %f' % (item, j, similarity))
        simTotal += similarity
        ratSimTotal += similarity * userRating
    if simTotal == 0: 
        return(0)
    else: 
        return(ratSimTotal/simTotal)
################################################################


####(3)推荐服务  ：  ###########################################
def recommend(dataMat, user, N, simMeas,estMethod): 
    unratedItems = nonzero(dataMat[user,:].A==0)[1]#find unrated items #寻找未评级的物品
    if len(unratedItems) == 0: 
        retur('you rated everything')
    itemScores = []
    for item in unratedItems:
        estimatedScore = estMethod(dataMat, user, simMeas, item)
        print(estimatedScore)
        itemScores.append((item, estimatedScore))
    return(sorted(itemScores, key=lambda jj: jj[1], reverse=True)[:N]) #寻找前N个未评级物品
################################################################    
#_______________________________________________________________________________________________




#_______________________________________________________________________________________________
#step 1:input---------------------
myMat=mat([[4, 4, 0, 2, 2],
           [4, 0, 0, 3, 3],
           [4, 0, 0, 1, 1],
           [1, 1, 1, 2, 0],
           [2, 2, 2, 0, 0],
           [1, 1, 1, 0, 0],
           [5, 5, 5, 0, 0]])

dish_list = ['鳗鱼饭','日式炸鸡排','寿司饭','烤牛肉','手撕猪肉']
user_list = ['Ed','Peter','Tracy','Fan','Ming','Pachi','Jocelyn'];
user_ID   = 2;#Tracy  
dish_ID_1 = 1;#日式炸鸡饭  
dish_ID_2 = 2;#寿司饭
#-----------------------------------


#step 2:推荐系统---------------------
#(1)相似度  :ecludSim,cosSim,pearsSim
#(2)推荐引擎:standEst,svdEst          #传统推荐,SVM                         
rr        = recommend(myMat,user_ID,2,pearsSim,standEst);print(rr)  #皮尔逊相关系数+传统评分
#rr       = recommend(myMat,user_ID,2,cosSim,svdEst);print(rr)       #余弦相似度+基于SVM评分 
#rr       = recommend(myMat,user_ID,2,ecludSim,svdEst);print(rr)      #欧式距离+基于SVM评分 
#-----------------------------------


#step 3:结果展示---------------------
print("_______________________________________________________")    
print('向顾客%s推荐的第一个菜肴为："%s"，该菜肴分数为%.4f' %(user_list[user_ID],dish_list[rr[0][0]],rr[0][1]))
print('向顾客%s推荐的第二个菜肴为："%s"，该菜肴分数为%.4f' %(user_list[user_ID],dish_list[rr[1][0]],rr[1][1]))
print("_______________________________________________________") 
#-----------------------------------
#_______________________________________________________________________________________________



#==============================================================================
# #备用---------------------
# cc=standEst(myMat,user_ID, pearsSim, dish_ID_1);print('顾客%s对菜肴"%s"的喜好为%.6f'%(user_list[user_ID],dish_list[dish_ID],cc)) 
# cc=standEst(myMat,user_ID, pearsSim, dish_ID_2);print('顾客%s对菜肴"%s"的喜好为%.6f'%(user_list[user_ID],dish_list[dish_ID],cc)) 
# #-----------------------------------
#==============================================================================
