/*�˳����������1��1000�������е�������������
              2020��10��28��
	    made by ���ķ� 9201010E0632
*/
# include <stdio.h>
int main ()
{
    //ǰ��׼��
	int n=1,sum,i;
	printf ("1��1000�ڵ��������������У�\n");
	

	//�㷨����
	while (n<=1000)
	{
	  sum=0;
	  for (i=1;i<n;i++)                       
	  if (n%i==0) 
		  sum+=i;                           //��������֮��
	  if (sum==n)                           //�ж�ĳ���Ƿ�Ϊ���������������������
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