#include <stdio.h>
int gcd(int a,int b)
{
    if (a%b == 0)
        return b;
    else
        gcd(b,a%b);
}
int main()
{
    int a = 0,b = 0;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}