#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    if (x >= 0 && x < 10)
        return true;

    stack<short int> stack;
    short int digit = (short int)log10(x) + 1;
    int index(0);

    if ( digit%2 == 0 )
    {
        while(x != 0)
        {
            if (index < digit/2)
                stack.push((short int)(x%10));
            else if (x%10 == stack.top())
                stack.pop();
            x /= 10;
            index++;
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
    else
    {
        while(x != 0)
        {
            if (index < digit/2)
                stack.push((short int)(x%10));
            else if (x%10 == stack.top() && index != digit/2)
                stack.pop();
            x /= 10;
            index++;
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
}

int producePrimeNumber(const int begin,const int end,vector<int> *target)
{
    int count(0);
    bool flag(true);
    bitset<100000000> PrimeNumber;
    PrimeNumber.set();
    for (int i(5);i*i <= end;i++)
    {
        if (PrimeNumber.test(i-1) == false)
            continue;
        for (int j(2);j*j <= i;j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            for (int n(i*i);n < end;n+=i)
                PrimeNumber.set(n-1,false);
        flag = true;
    }
    for (int i(begin);i < end;i++)
    {
        if (PrimeNumber.test(i-1))
        {
            target->push_back(i);
            count++;
        }
    }
    return count;
}

int main()
{
    int a(0),b(0);
    vector<int> primeNumber;
    cin >> a >> b; 
    int sum = producePrimeNumber(a,b,&primeNumber);
    for (int i(0);i < sum;i++)
        if (isPalindrome(primeNumber.at(i)) == true)
            cout << primeNumber.at(i) << endl;
    return 0;
}