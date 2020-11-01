/*此程序用来输出1到599中某一位上有3的素数，每10个换一行
2020年10月28日
made by 汪文峰 9201010E0632
*/
#include <stdio.h>
#include <math.h>
int main ()
{
    //算法主体
    int a[599],b[599],i,k,n=1;
    for (i=0; i<=598; i++)
    {
        a[i]=i;                                                //将1到599储存在数组a中
        if (i%10==3||(i/10)%10==3||((i/10)/10)==3)          //判断是否有某一位上的数为3
        {
            for (k=2; k<=sqrt (a[i]); k++)                     //判断是否为素数
                if (a[i]%k==0) 
                    break;
            if ( k>sqrt (a[i]))
            {
                b[n]=a[i];                                     //将满足条件的值存入数组b中
                n++;
                k=0;
            }
        }
    }
    //数据输出
    n--;
    printf ("1到599中至少有一位为3的素数有%d个,分别为:\n",n);
    for ( i=1; i<=n; i++)                                      //控制换行
    {
        printf ("b[%d]=%d\t",i,b[i]);
        if (i % 10 == 0)
            printf ("\n");
    }
	printf ("\n");
    return 0;
}