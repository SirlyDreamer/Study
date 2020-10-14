#include <stdio.h>
int main()
{
    int a,b,astatus = 0,bstatus = 0;
    scanf("%d %d",&a,&b);
    switch (a%10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            astatus = 1;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            astatus = 2;
            break;
        default:
            break;
    }
    switch (b%10)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            bstatus = 1;
            break;
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            bstatus = 2;
            break;
        default:
            break;
    }
    if (astatus == 0 || bstatus == 0)
    {
        printf("it is error");
        return 0;
    }
    if (astatus == 2 && bstatus == 2)
    {
        printf("it is pass");
        return 0;
    }
    printf("it is not pass");
    return 0;
}