#include <stdio.h>
#include <string.h>
struct stack
{
    char data[8] = {""};
    int tail = 0;
};
struct stack s;
void pushStack(char data)
{
    s.data[s.tail] = data;
    s.tail++;
    return;
}
char getStack()
{
    return s.data[s.tail-1];
}
bool emptyStack()
{
    if (s.tail > 0)
        return 0;
    else
        return 1;
}
void popStack()
{
    if (emptyStack() == 0)
        s.tail--;
    return;
}
int main()
{
    char str[6] = "";
    scanf("%s",&str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
        pushStack(str[i]);
    for (int i = 0; i < n; i++)
    {
        printf("%c",getStack());
        popStack();
    }
    return 0;
}