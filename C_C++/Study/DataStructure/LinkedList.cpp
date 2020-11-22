#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace std;

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
    viewList(head);
    cout << endl << "---------------------------------" << endl;
    cout << "Input a number to add." << endl;
    int t(0);
    cin >> t;
    point = searchNode(head,t);
    if (point == NULL)
        insertNode(t,tail);
    else
        insertNode(t,point);
    cout << endl << "---------------------------------" << endl;
    viewList(head);
    cout << endl << "---------------------------------" << endl;
    cout << "Input a number to delete." << endl;
    cin >> t;
    point = searchNode(head,t);
    if (point == NULL)
        cout << "Node not found" << endl;
    else
        deleteNode(point,point->next);
    cout << endl << "---------------------------------" << endl;
    viewList(head);
    deleteList(head);
    head = NULL;
    tail = NULL;
    return 0;
}