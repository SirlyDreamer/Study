#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *temp1;
struct node *temp2;
struct node *head; 
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
void insertNode(int data,struct node *previous)
{
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = previous->next;
    previous->next = temp1;
}
int main()
{   
    head = NULL;
    for (int i=1;i<=10;i++)
    {   
        printf ("%d  ",i);
        addNode(i);
    }
    printf("\n---------------------------------\n");
    struct node *point;
    point = head;
    while (point != NULL)
    {
        printf("%d  ",point->data);
        point = point->next;
    }
    printf("\n---------------------------------\n");
    int t;
    scanf("%d",&t);
    point = head;
    while (point != NULL)
    {
        if (point->next == NULL || point->next->data > t)
        {
            insertNode(t,point);
            break;
        }
        point = point->next;
    }
    point = head;
    while (point != NULL)
    {
        printf("%d  ",point->data);
        point = point->next;
    }
    return 0;
}