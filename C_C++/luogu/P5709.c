#include <stdio.h>
int main()
{
    int m=0,t=0,s=0;
    scanf("%d %d %d",&m,&t,&s);
    int num = 0;
    if (t == 0)
        num = 0;
    else
    {
        if (s % t == 0)
            num = m-(s/t);
        else
            num = m-((s/t)+1);
    }
    if (num < 0)
        num = 0;
    printf("%d",num);
    return 0;
}