/*此程序用来计算sin(x)的值，当通项小于1e-6时输出，使用时请从键盘上读入2.5
                           2020年10月28日
                   made by 汪文峰 9201010E0632
*/


# include <stdio.h>
# include <math.h>
int main ()
{


  //数据准备  temp用来储存阶乘
	double x,sum,temp;
	 int sign=-1,i;
	 printf ("请输入x:");
	scanf ("%lf",&x);


  //初始化sum和temp
	sum=temp=x;


  //算法主体
	for (i=3;fabs(temp)>=1e-6;i+=2)
		sum+=temp*=sign*x*x/((i-1)*i);


  //数据输出
	printf ("sin(%lf))=%lf\n",x,sum);
	return 0;
}