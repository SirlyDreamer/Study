#include <iostream>
#include <cmath>
using namespace std;
bool isPrimeNumber(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i < (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int max(0);
    cin >> max;
    for (int a = max;a >= 5; a--)
        if (isPrimeNumber(a-2) && isPrimeNumber(a))
        {
            cout << a-2 << ' ' << a;
            break;
        }
    return 0;
}