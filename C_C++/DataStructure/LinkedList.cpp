#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node* head = NULL;
struct node* tail = NULL;
void addNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
        head = newnode;
    else
        tail->next = newnode;
    tail = newnode;
    return;
}
void insertNode(int data,struct node *forward)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = forward->next;
    forward->next = newnode;
    return;
}
void deleteNode(struct node* prev,struct node* place)
{
    struct node* temp1 = prev;
    struct node* temp2 = place;
    temp1->next = temp2->next;
    free(temp2);
    return;
}
void deleteList(struct node* head)
{
    struct node* temp1 = head;
    struct node* temp2 = head->next;
    while (temp1 != NULL)
    {
        free(temp1);
        temp1 = temp2;
        if (temp2 != NULL)
            temp2 = temp2->next;
    }
    return;
}
int main()
{
    for (int i=0;i<10;i++)
    {
        cout << i << ' ';
        addNode(i);
    }
    struct node *point;
    point = head;
    cout << endl << "---------------------------------" << endl;
    while (point != NULL)
    {
        cout << point->data << ' ';
        point = point->next;
    }
    cout << endl << "---------------------------------" << endl;
    int t;
    cin >> t;
    point = head;
    while (point->next != NULL && point->data < t)
        point = point->next;
    insertNode(t,point);
    cout << endl << "---------------------------------" << endl;
    point = head;
    while (point != NULL)
    {
        cout << point->data << ' ';
        point = point->next;
    }
    cout << endl << "---------------------------------" << endl;
    cin >> t;
    point = head;
    while (point->next != NULL && point->next->data != t)
        point = point->next;
    deleteNode(point,point->next);
    cout << endl << "---------------------------------" << endl;
    point = head;
    while (point != NULL)
    {
        cout << point->data << ' ';
        point = point->next;
    }
    deleteList(head);
    return 0;
}