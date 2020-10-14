#include <stdio.h>
#include <string.h>
int main()
{
    int base = 0,t = 0;
    char digit[1000] = {""};
    scanf("%d %s",&base,&digit);
    int n = strlen(digit);
    for (int i = n; i > 0; i--)
    {
        if (digit[n-i] != '0' )
            {
                if (t == 1)
                    printf("+");
                printf("%c*%d^%d",digit[n-i],base,i-1);
                t = 1;
            }
    }
    return 0;
}