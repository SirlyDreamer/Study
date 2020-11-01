/*此程序用来输出1到1000内整数中的完数及其因子
              2020年10月28日
	    made by 汪文峰 9201010E0632
*/
# include <stdio.h>
int main ()
{
    //前置准备
	int n=1,sum,i;
	printf ("1到1000内的完数及其因子有：\n");
	

	//算法主体
	while (n<=1000)
	{
	  sum=0;
	  for (i=1;i<n;i++)                       
	  if (n%i==0) 
		  sum+=i;                           //计算因子之和
	  if (sum==n)                           //判断某数是否为完数并输出完数及其因子
	{
	  printf ("%d its factors are",n);    
	  for (i=1;i<n;i++)
	  if (n%i==0) 
	   printf ("%d,",i);
	  printf ("\b \n");
	}
	n++;
	}
	return 0;
}