#include <stdio.h>
int main()
{
    int height[10] = {0};
    int h;
    int sum = 0;
    for (int i = 0; i < 10; i++)
        scanf("%d ",&height[i]);
    scanf("%d",&h);
    for (int i = 0; i < 10; i++)
    {
        if (height[i] <= h+30)
            sum ++;
    }
    printf("%d",sum);
    return 0;
}