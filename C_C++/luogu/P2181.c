#include <stdio.h>
int main()
{
    unsigned long long n,sum=0;
    scanf("%llu",&n);
    sum = (n*(n-1)*(n-2)*(n-3))/(4*3*2*1);
    printf("%llu",sum);
    return 0;
}