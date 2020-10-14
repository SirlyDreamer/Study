#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,p,s,S;
    scanf("%lf %lf %lf",&a,&b,&c);
    p = 0.5*(a+b+c);
    s = p*(p-a)*(p-b)*(p-c);
    S = sqrt(s);
    printf("%.1lf",S);
    return 0;
}