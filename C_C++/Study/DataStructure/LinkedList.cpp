#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* head = nullptr;
struct node* tail = nullptr;

void addNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == nullptr)
    {
        cout << "Allocate Memory Failed" << endl;
    }
    else
    {
        newnode->data = data;
        newnode->next = nullptr;
        if (head == nullptr)
            head = newnode;
        else
            tail->next = newnode;
        tail = newnode;
    }
    return;
}

void insertNode(int data, struct node* forward)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == nullptr)
    {
        cout << "Allocate Memory Failed" << endl;
    }
    else
    {
        newnode->data = data;
        newnode->next = forward->next;
        forward->next = newnode;
    }
    return;
}

void deleteNode(struct node* prev, struct node* place)
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
    while (temp1 != nullptr)
    {
        free(temp1);
        temp1 = temp2;
        if (temp2 != nullptr)
            temp2 = temp2->next;
    }
    return;
}

struct node* searchNode(struct node* head, int target)
{
    struct node* point = head;
    while (point->next != nullptr && point->data != target)
        point = point->next;
    if (point == tail)
        return nullptr;
    else
        return point;
}

void viewList(struct node* head)
{
    struct node* point = head;
    while (point != nullptr)
    {
        cout << point->data << ' ';
        point = point->next;
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << ' ';
        addNode(i);
    }
	
    struct node* point;
    point = head;
    cout << endl << "---------------------------------" << endl;
    viewList(head);
    cout << endl << "---------------------------------" << endl;
	
    cout << "Input a number to add." << endl;
    int t(0);
    cin >> t;
    point = searchNode(head, t);
    if (point == nullptr)
        insertNode(t, tail);
    else
        insertNode(t, point);
    cout << endl << "---------------------------------" << endl;
    viewList(head);
    cout << endl << "---------------------------------" << endl;
	
    cout << "Input a number to delete." << endl;
    cin >> t;
    point = searchNode(head, t);
    if (point == nullptr)
        cout << "Node not found" << endl;
    else
        deleteNode(point, point->next);
    cout << endl << "---------------------------------" << endl;
    viewList(head);
	
    deleteList(head);
    head = nullptr;
    tail = nullptr;
    return 0;
}