#include <stdio.h>
#include <math.h>
int main()
{
    int counter = 0;
    int flag = 1;
    for (int i = 2;i <= 100;i++)
    {   
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d ",i);
            counter ++;
        }
        if (counter == 5)
        {
            printf("\n");
            counter = 0;
        }
        flag = 1;
    }
    return 0;
}