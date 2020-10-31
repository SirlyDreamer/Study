#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stack;
    int data(0);

    while (cin >> data)
        stack.push(data);

    while (stack.empty() == false)
    {
        cout << stack.top() << ' ';
        stack.pop();
    }
    
    return 0;
}