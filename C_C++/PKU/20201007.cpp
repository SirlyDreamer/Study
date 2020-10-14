#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n(0),num(0);
    cin >> n;
    char str[100] = {};
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            n = (n - 2) / 2;
            str[num] = 'G';
            num++;
        }
        else
        {
            n = (n - 1) / 2;
            str[num] = 'N';
            num++;
        }
    }
    for (int i = num; i >= 0; i--)
        cout << str[i];
    return 0;
}