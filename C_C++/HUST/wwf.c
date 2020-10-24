#include <stdio.h>
int main ()
{
    for (int i = 1 ; i <= 9 ; i++)
    {
        for (int j = i - 1 ; j > 0 ; j--)
            printf("\t");
        for (int j = i ; j <= 9 ; j++)
            printf("%d*%d=%d\t",i,j,i*j);
        printf("\n");
    }
    return 0;
}