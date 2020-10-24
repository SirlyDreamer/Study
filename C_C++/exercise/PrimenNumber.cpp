#include <iostream>
#include <cmath>
using namespace std;
int main()
{   
    bool flag(true);
    cout << 2 << ' ';
    for (int i(3);i <= 100;i++)
    {
        for (int j(2);j < (int)sqrt(i);j++)
            if (i % j == 0)
                flag = false;
        if (flag)
            cout << i << ' ';
        flag = true;
    }
    return 0;
}