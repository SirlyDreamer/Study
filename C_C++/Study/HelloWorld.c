#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "ab\n\012\\\"";
    printf("%s %d",str,strlen(str));
    return 0;
}