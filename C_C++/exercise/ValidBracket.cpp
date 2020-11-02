#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool match(char left,char right)
{
    if (left == '(' && right == ')')
        return true;
    if (left == '[' && right == ']')
        return true;
    if (left == '{' && right == '}')
        return true;
    return false;
}

bool isValid(string s)
{
    if (s.size() == 0)
        return true;

    stack<char> stack;

    for (string::iterator iter = s.begin() ; iter != s.end() ; iter++)
    {
        if (stack.empty() == true || !match(stack.top(),*iter))
            stack.push(*iter);
        else
            stack.pop();
    }

    if (stack.empty() == true)
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s);
    return 0;
}