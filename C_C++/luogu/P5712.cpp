#include <cstdio>
using namespace std;
int main()
{
    int num = 0;
    scanf("%d",&num);
    if (num <=1)
        printf("Today, I ate %d apple.",num);
    else
        printf("Today, I ate %d apples.",num);
    return 0;
}