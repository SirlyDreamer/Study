#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};
 
int LN_to_int(ListNode* source)
    {
        int num(0);
        int digit(1);
        while (source->next != nullptr)
        {
            num += source->val*digit;
            digit *= 10;
            source = source->next;
        }
        return num;
    }

ListNode* int_to_LN(int source)
{
    struct ListNode *head = new struct ListNode;
    struct ListNode *tail = head;
    while (source != 0)
    {
        struct ListNode *temp = new struct ListNode;
        temp->val = source % 10;
        temp->next = nullptr;
        source /= 10;
        tail->next = temp;
        tail = temp; 
    }
    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int a(0),b(0);
    a = LN_to_int(l1);
    b = LN_to_int(l2);
    struct ListNode *result = int_to_LN(a+b);
    return result;
}

int main()
{
    
}