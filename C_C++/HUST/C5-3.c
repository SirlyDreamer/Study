/*次程序用来计算x^( 1/3),当相邻两项的差的绝对值小于1e-5是输出结果，使用时请输入0.75
2020年10月28日
made by 汪文峰 9201010E0632
*/

# include <stdio.h>
# include <math.h>
int main ( )
{
   //数据输入
    double y0,y1,x;
    printf ( "请输入x:");
    scanf ( "%lf",&x);


   //y0和y1的初始化
    y0=x;
    y1=2.0/3*y0+x/( 3*y0*y0);
    
    
  //算法主体
    do
    {
        y0=y1;
        y1=2.0/3*y0+x/( 3*y0*y0);
    }
    while ( fabs ( y0-y1)>1e-5);
   
   
   //数据输出
    printf ( "y=%lf^( 1/3)=%lf\n",x,y1);
    return 0;
}