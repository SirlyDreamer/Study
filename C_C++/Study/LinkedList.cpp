#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *temp1;
struct node *temp2;
void addNode(int data)
{
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;
    if (head == NULL)
        head = temp1;
    else
        temp2->next = temp1;
    temp2 = temp1;
}
void insertNode(int data,struct node *forward)
{
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = forward->next;
    forward->next = temp1;
}
int main()
{
    head = NULL;
    for (int i=0;i<10;i++)
    {
        printf("%d  ",i);
        addNode(i);
    }
    struct node *point;
    point = head;
    printf("\n---------------------------------\n");
    while (point != NULL)
    {
        printf("%d  ",point->data);
        point = point->next;
    }
    printf("\n---------------------------------\n");
    int t;
    scanf("%d",&t);
    point = head;
    while (point->next != NULL && point->data < t)
        point = point->next;
    insertNode(t,point);
    printf("\n---------------------------------\n");
    point = head;
    while (point != NULL)
    {
        printf("%d  ",point->data);
        point = point->next;
    }
    return 0;
}