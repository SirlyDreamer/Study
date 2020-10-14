#include <stdio.h>
int main()
{
    int a = 0,b = 0,c = 0;
    scanf("%d %d %d",&a,&b,&c);
    if (a == b && b == c)
    {
        printf("1");
        return 0;
    }
    if ((a == b && a != c) || (a == c && a != b) || (b == c && a != b))
    {
        printf("2");
        return 0;
    }
    if ( a+b > c && a+c > b && b+c > a)
    {
        printf("3");
        return 0;
    }
    printf("0");
    return 0;
}