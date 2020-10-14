#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    float m = 0,h = 0;
    float BMI = 0;
    scanf("%f %f",&m,&h);
    BMI = m / (h*h);
    if (BMI < 18.5)
        printf("Underweight");
    if (BMI >= 18.5 && BMI < 24)
        printf("Normal");
    if (BMI >= 24)
        printf("%.6g\nOverweight",BMI);
    return 0;
}