#include <stdio.h>
int main()
{
    char string[1024576] = {'\0'};
    int i = 0;
    while(scanf("%c",&string[i]) != EOF)
        i++;
    i = 0;
    while(string[i] != '\0')
    {   if (string[i] == ' ' && string[i+1] == ' ');
        else
            printf("%c",string[i]);
        i++;
    }
    return 0;
}