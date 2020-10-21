#include <stdio.h>
int main()
{
    int T,string[1000];
    scanf("%d",&T);
    for (int i = 0;i < T;i++)
        scanf("%d",&string[i]);
    for (int i = 0;i < T;i++)
        printf("%c",string[i]);
    return 0;
}