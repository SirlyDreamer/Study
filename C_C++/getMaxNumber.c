#include <stdio.h>
int main ()
{
    int max(int x,int y,int z);
    int a,b,c,e,goon = 1;
    while(goon == 1)
    {
        printf("请输入三个整数\n");
        scanf ( "%d,%d,%d",&a,&b,&c);
        e=max (a,b,c);
        printf ( "max=%d\n",e);
        printf("是否继续?(继续请输入1,退出请输入0)");
        scanf("%d",&goon);
    }
    return 0;
}
int max (int x,int y,int z)
{ 
    if(x>=y)
        if(x>=z)
            return x;
        else
            return z;
    else
        if(y>=z)
            return y;
        else
            return z;
}