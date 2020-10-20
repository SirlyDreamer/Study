#include <iostream>
using namespace std;
struct stack
{
    int data[128] = {0};
    int tail = 0;
};
struct stack s;
void pushStack(int data)
{
    s.data[s.tail] = data;
    s.tail++;
    return;
}
int getStack()
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
    for (int i=1;i<=10;i++)
    {
        printf("%d  ",i);
        pushStack(i);
    }
    printf("\n---------------------------------\n");
    for (int i=0;i<10;i++)
    {
        printf("%d  ",getStack());
        popStack();
    }
    printf("\n---------------------------------\n");
    printf("%d",emptyStack());
    return 0;
}