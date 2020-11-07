#include <iostream>
using namespace std;

int killBat(int num)
{
    if (num == 0)
        return 0;
    if (num%2 == 0)
    {
        num /= 2;
        return killBat(num);
    }
    else
    {
        num --;
        return killBat(num) + 1;
    }
}

int main()
{
    int num(0),C(0);
    cin >> C;
    for (int i;i<C;i++)
    {
        cin >> num;
        cout << killBat(num) << endl;
    }
    return 0;
}