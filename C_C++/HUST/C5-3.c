/*�γ�����������x^( 1/3),����������Ĳ�ľ���ֵС��1e-5����������ʹ��ʱ������0.75
2020��10��28��
made by ���ķ� 9201010E0632
*/

# include <stdio.h>
# include <math.h>
int main ( )
{
   //��������
    double y0,y1,x;
    printf ( "������x:");
    scanf ( "%lf",&x);


   //y0��y1�ĳ�ʼ��
    y0=x;
    y1=2.0/3*y0+x/( 3*y0*y0);
    
    
  //�㷨����
    do
    {
        y0=y1;
        y1=2.0/3*y0+x/( 3*y0*y0);
    }
    while ( fabs ( y0-y1)>1e-5);
   
   
   //�������
    printf ( "y=%lf^( 1/3)=%lf\n",x,y1);
    return 0;
}