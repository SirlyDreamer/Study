import time

import os

import sys

ID = input("请输入你的学号作为ID：")   # 将学号作为用户的账号   

TicketSold_System = {"1":0,"2":0,"3":0,"4":0,"5":0}   # 各车次已售票数

TicketSold_User = {"1":0,"2":0,"3":0,"4":0,"5":0}   # 用户购买车票数

TicketLeft = {"1":50,"2":40,"3":40,"4":40,"5":50}

TicketBought = {}          # 当前id购票总数纪录

TimeDict = {"1":640,"2":930,"3":1300,"4":1600,"5":2000}  # 车次对应时间的字典

Y = y = False

N = n = True

##########   封装用户交互界面   #########

def mainMenu():

    os.system("cls")
    
    print("+---------------------欢迎进入巴士售票管理系统-------------------------+\n"
          "|                            主菜单                                    |\n"
          "|                  [1] 保存订票信息(需要管理员验证)　　     　         |\n"
          "|                  [2] 订票                                            |\n"
          "|                  [3] 退票                                            |\n"
          "|                  [4] 显示系统订票信息                                |\n"
          "|                  [5] 显示当前ID订票信息                              |\n"
          "|                  [0] 退出系统                                        |\n"
          "+----------------------------------------------------------------------+\n"
          "*输入选项前的数字并回车进入相应系统*\n" )
    
    choice = eval(input())

    while (choice not in [0,1,2,3,4,5]):     # 防止用户输入错误信息

        choice = eval(input("输入错误，请重新输入"))
    
    if (choice==1):         #跳转各函数
        update ()
    if (choice==2):
        orderTicket (ID)
    if (choice==3):
        refund (ID)
    if (choice==4):
        getTicketInfo()
    if (choice==5):
        getPassengerInfo()
    if (choice==0):
        exitSystem () 


def getTicketInfo():

    os.system("cls")

    print("    班次    发车时间    载客量    已售票数    \n\n"
   	      "     1       06:40       50        {}       \n"
          "     2       09:30       40        {}       \n"
          "     3       13:00       40        {}       \n"
          "     4       16:00       40        {}       \n"
          "     5       20:00       50        {}       \n"
          .format(TicketSold_System["1"],TicketSold_System["2"],TicketSold_System["3"],TicketSold_System["4"],TicketSold_System["5"]))

    os.system("pause")

    mainMenu()

def getPassengerInfo():

    os.system("cls")

    print("ID:{}".format(ID) + "的购票情况为\n")
    
    print("    班次    发车时间    已购票数    \n\n"
   	      "     1       06:40        {}      \n"
          "     2       09:30        {}      \n"
          "     3       13:00        {}      \n"
          "     4       16:00        {}      \n"
          "     5       20:00        {}      \n"
          .format(TicketSold_User["1"],TicketSold_User["2"],TicketSold_User["3"],TicketSold_User["4"],TicketSold_User["5"]))

    os.system("pause")

    mainMenu()
    
###########  读取配置文件  ############

def readProfile():

    path = os.path.abspath(os.path.dirname(sys.argv[0]))   # 相对路径
    
    with open(path + "\\myfile.txt", 'r+',encoding="utf-8") as dict_file:  #读写txt文件

        for line in dict_file:
            
            (key, value) = line.strip(";").split(",")         # 将txt文件的数据以“ key , value ”的形式写入字典
            
            TicketBought[key] = int(value)

        for line in dict_file:

            (key,value) = line.strip(";").split(",")   # 将txt文件的数据以“ key , value ”的形式写入字典
            
            TicketSold_System[key] = int(value)


###########   开始函数   #############

def begin():                          
 
    if (ID not in TicketBought):
        
        TicketBought[ID] = 0

    mainMenu()    #进入主菜单
	
###########   订票   ##############
              
def orderTicket (ID):
             
    exitSystemStatus = False

    while(exitSystemStatus == False):  #用户输入n时退出购票
    ##显示订票信息

        os.system("cls")

        print("    班次    发车时间    载客量    已售票数    \n\n"
   	      "     1       06:40       50        {}       \n"
          "     2       09:30       40        {}       \n"
          "     3       13:00       40        {}       \n"
          "     4       16:00       40        {}       \n"
          "     5       20:00       50        {}       \n"
          .format(TicketSold_System["1"],TicketSold_System["2"],TicketSold_System["3"],TicketSold_System["4"],TicketSold_System["5"]))

        CurrentTime = int(time.strftime("%H%M"))    #获取当前时间格式化并转为整形
        
        service = input("请输入购车班次：")

        while (service not in ["1","2","3","4","5"]):     # 防止用户输入错误信息

            service = input("输入错误，请重新输入")
        
        LeaveTime = int(TimeDict[service])           #用户购买车次对应的时间
        
        if(CurrentTime <= LeaveTime):             #当前时间小于发车时间
            
            if (TicketBought[ID] < 5):

                if (TicketLeft[service] <= 0):

                    print("非常抱歉，该班次的票卖完了，请选择其他班次\n")

                    exitSystemStatus = eval(input("是否继续购票？(y/n)\n"))

                    while (exitSystemStatus not in [True,False]):     # 防止用户输入错误信息

                        exitSystemStatus = eval(input("输入错误，请重新输入\n"))
    
                else :
                                
                    TicketSold_System[service] += 1          #已售票数加一
                
                    TicketSold_User[service] += 1
        
                    TicketLeft[service] -= 1

                    TicketBought[ID] += 1      #此用户购票数加一
                    
                    print("购票成功\n购票时间：{}\n\n".format(time.strftime("%d日-%H时-%M分")))
                    
                    exitSystemStatus = eval(input("是否继续购票？(y/n)\n\n"))

                    while (exitSystemStatus not in [True,False]):     # 防止用户输入错误信息

                        exitSystemStatus = eval(input("输入错误，请重新输入\n"))
                
            else :                 #用户购票数大于5，跳出循环
                
                print("每个ID最多可以购买5张票，您已超出上限!即将返回主菜单\n\n")
                
                os.system("pause")

                break
              
        else :              
            
            print("当前时间超出发车时间\n")      #跳出循环
            
            exitSystemStatus = eval(input("是否继续购票?(y/n)\n"))

            while (exitSystemStatus not in [True,False]):     # 防止用户输入错误信息

                exitSystemStatus = eval(input("输入错误，请重新输入\n"))
 
    mainMenu()    #返回主菜单

##########   退票函数   ###########

def refund (ID):

    exitSystem = False

    while(exitSystem == False):  #用户输入“False”时退出退票
    #显示用户订票信息
        os.system("cls")

        print("ID:{}".format(ID) + "的购票情况为\n")
    
        print("    班次    发车时间    已购票数    \n\n"
   	          "     1       06:40        {}      \n"
              "     2       09:30        {}      \n"
              "     3       13:00        {}      \n"
              "     4       16:00        {}      \n"
              "     5       20:00        {}      \n"
              .format(TicketSold_User["1"],TicketSold_User["2"],TicketSold_User["3"],TicketSold_User["4"],TicketSold_User["5"]))

        CurrentTime = int(time.strftime("%H%M"))    #获取当前时间并转为整形
        
        service = input("请输入退票车班次：")

        while (service not in ["1","2","3","4","5"]):     # 防止用户输入错误信息

            service = input("输入错误，请重新输入")
        
        LeaveTime = int(TimeDict[service])           #用户退票车次对应的时间

        if(CurrentTime <= LeaveTime):               #当前时间小于发车时间

            if (TicketSold_System[service] <= 0) :

                print("您未购买此车票，退票失败\n")

                exitSystem = eval(input("是否继续退票?(y/n)\n"))

                while (exitSystem not in [True,False]):     # 防止用户输入错误信息

                    exitSystem = eval(input("输入错误，请重新输入\n"))

            else :
                            
                TicketSold_System[service] -= 1    #已售票减一
                
                TicketSold_User[service] -= 1                     
                
                TicketBought[ID] -= 1    #此用户购票减一
                
                TicketLeft[service] += 1      #余票加一

                print("退票成功\n退票时间：{}\n\n".format(time.strftime("%d日-%H时-%M分")))
            
                exitSystem = eval(input("是否继续退票?(y/n)\n"))

                while (exitSystem not in [True,False]):     # 防止用户输入错误信息

                    exitSystem = eval(input("输入错误，请重新输入\n"))
     
        else:
            
            print("当前时间超出发车时间\n\n")      #跳出循环
            
            exitSystem = eval(input("是否继续退票?(y/n)\n"))

            while (exitSystem not in [0,1]):     # 防止用户输入错误信息

                exitSystem = eval(input("输入错误，请重新输入"))
              
    mainMenu()    #返回主菜单

##########   将数据写入txt文件函数   ##########

def update ():

    path = os.path.abspath(os.path.dirname(sys.argv[0]))    # 相对路径
    
    f = open(path + "\\myfile.txt",'r+',encoding='utf-8')  #打开文件并写入
        
    for k,v in TicketBought.items():   # 遍历字典中的键值对
            
        v = str(v)                    # 把字典的值转换成字符型
            
        f.write(k + ',')              # 将键值对以“ key ： value ”形式写入txt文件
        f.write(v + ';')

    f.write('\n')
    
    for k,v in TicketSold_System.items():

        v = str(v)

        f.write(k + ',')
        f.write(v + ';')

    f.write('\n')

    f.close()
    
    path = os.path.abspath(os.path.dirname(sys.argv[0]))    # 相对路径
    
    g = open(path + "\\myfile.txt",'a',encoding='utf-8')  #以追加方式打开文件

    a = ("    班次    发车时间    载客量    已售票数       \n"
        "     1       06:40       50        {}          \n"
        "     2       09:30       40        {}          \n"
        "     3       13:00       40        {}          \n"
        "     4       16:00       40        {}          \n"
        "     5       20:00       50        {}          \n"
        .format(TicketSold_System["1"],TicketSold_System["2"],TicketSold_System["3"],TicketSold_System["4"],TicketSold_System["5"]))
        
    for i in a:
       
        g.write(i)     #将 a 信息写入txt文件

    print("文件写入成功！即将返回主菜单")

    os.system("pause")
    
    mainMenu()    #返回主菜单

##########   退出函数   ###########

def exitSystem ():

    print("感谢您的乘车，祝您旅途愉快！！！")
    
##########   main函数   ########## 

def main():

    readProfile()
    begin()
    
main()