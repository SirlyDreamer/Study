#include <stdio.h>
int main()
{
    int a=0,b=0,c=0,d=0;
    int e=0,f=0;
    int beginmin=0,endmin=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    beginmin = 60*a + b;
    endmin = 60*c + d;
    int time = endmin-beginmin;
    e = time/60;
    f = time%60;
    printf("%d %d",e,f);
    return 0;
}