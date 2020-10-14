#include <cstdio>
using namespace std;
int main()
{
    int year = 0;
    bool LeapYear = false;
    scanf("%d",&year);
    if (year%400 == 0 || (year%4 == 0)&&(year%100 != 0))
        LeapYear = true;
    printf("%d",LeapYear);
    return 0;
}