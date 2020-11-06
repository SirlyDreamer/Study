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
    bitset<10000000> PrimeNumber;
    PrimeNumber.set();
    for (int i(begin);i <= end;i++)
    {
        if (PrimeNumber[i] == false)
            continue;
        double limit = sqrt(i);
        for (int j(2);j <= limit;j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            target->push_back(i);
            for (int n(1);i*n < end;n++)
                PrimeNumber.set((int)(i*n),false);
            count++;
        }
        flag = true;
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