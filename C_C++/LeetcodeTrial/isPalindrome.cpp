#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        stack<short int> stack;
        short int digit = (short int)log10(x) + 1;

        if (digit == 1)
            return true;

        if ( digit%2 == 0 )
        {
            while(x != 0)
            {
                if (stack.empty() == true || (short int)(x%10) != stack.top())
                    stack.push((short int)(x%10));
                else
                    stack.pop();
                x /= 10;
            }
            if (stack.empty())
                return true;
            else
                return false;
        }
        else
        {
            int index(0);
            while(x != 0)
            {
                if (index != digit/2)
                {
                    if (stack.empty() == true || (short int)(x%10) != stack.top())
                        stack.push((short int)(x%10));
                    else
                        stack.pop();
                }
                x /= 10;
                index++;
            }
            if (stack.empty())
                return true;
            else
                return false;
        }
    }

int main()
{
    int n(0);
    cin >> n;
    cout << isPalindrome(n);
    return 0;
}