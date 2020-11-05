#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void order(int array[],int limit)
{
    int i,temp,n;
    for(i=0;i<limit;i++)
    {
        if(array[i]>array[i+1])
        {
            temp=array[i];
            array[i]=array[i+1],
            array[i+1]=temp;
        }
    }
    for(n=0;n<=limit;n++)
        printf("%d\t",array[n]);
}

int judge(int array[],int limit)
{
    int i,n,temp;
    for(i=0;i<limit;i++)
        for(n=i+1;n<=limit;n++)
            if(array[i]==array[n])
                return 0;
    return 1;
}

int main()
{
    int array[7],i,n,j,begin=1;
    while(begin == 1)
    {
        do
        {
            srand(time(NULL));
            for(i=0;i<=5;i++)
                array[i] = (rand() % 90+10);
            j = judge(array,5);
        }while(j == 0);
        order(array,5);
        printf("请输入想插入的数x\n");
        scanf("%d",array[6]);
        order(array,6);
        printf("输入1继续\n");
        scanf("%d",&begin);
    }
    return 0;
}
