/*�˳�����������sin(x)��ֵ����ͨ��С��1e-6ʱ�����ʹ��ʱ��Ӽ����϶���2.5
                           2020��10��28��
                   made by ���ķ� 9201010E0632
*/


# include <stdio.h>
# include <math.h>
int main ()
{


  //����׼��  temp��������׳�
	double x,sum,temp;
	 int sign=-1,i;
	 printf ("������x:");
	scanf ("%lf",&x);


  //��ʼ��sum��temp
	sum=temp=x;


  //�㷨����
	for (i=3;fabs(temp)>=1e-6;i+=2)
		sum+=temp*=sign*x*x/((i-1)*i);


  //�������
	printf ("sin(%lf))=%lf\n",x,sum);
	return 0;
}