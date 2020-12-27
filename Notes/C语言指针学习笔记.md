# C语言指针学习笔记
## 一. 取地址运算
运算符 `&` :取得变量的地址,操作数必须是变量  
## 二. 指针
指针是保存地址的变量  
写法: `int *p;` 和 `int* p;`   
注意:
* `int* p,q;` 和 `int *p,q;` 都只能得到指针 `p` 和整型变量 `q` ,若要表示申请指针 `p` 和 `q` ,应写为 ` int *p,*q;` 
* 指针的大小即一个 `int` 的大小  
* 指针前的 `int float double` 指的是指针所指变量的类型  
* `int*` 不是一种变量类型

## 三. 指针的应用场景
### 1 .交换两个变量的值
``` C
#include <stdio.h>
void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}
int main()
{
    int a = 1,b = 2;
    printf("a = %d,b = %d\n",a,b);+-
    swap (&a,&b);
    printf("a = %d,b = %d\n",a,b);
    return 0;
}
```
### 2 .（挖坑，不准备填了）