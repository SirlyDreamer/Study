#include <stdio.h>
#include <windows.h>
int main()
{
    int a = 0;
    int n = 0;
    while(1)
    {
        a = scanf("%d",&n);
        printf("a = %d n = %d\n",a,n);
        Sleep(1000);
    }
    return 0;
}