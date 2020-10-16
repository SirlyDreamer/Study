#include <iostream>
using namespace std;
struct Queue
{
    int data[128] = {0};
    int head = 0;
    int tail = 0;
};
struct Queue q;
void pushQueue(int data)
{
    q.data[q.tail] = data;
    q.tail ++;
    return;
}
int getQueue()
{
    return q.data[q.head];
}
bool emptyQueue()
{
    if (q.head == q.tail)
        return 1;
    else
        return 0;
}
void popQueue()
{
    if (emptyQueue() == 0)
        q.head++;
    return;
}
int main()
{
    for (int i=1;i<=10;i++)
    {
        printf("%d  ",i);
        pushQueue(i);
    }
    printf("\n---------------------------------\n");
    for (int i=0;i<10;i++)
    {
        printf("%d  ",getQueue());
        popQueue();
    }
    printf("\n---------------------------------\n");
    printf("%d",emptyQueue());
    return 0;
}