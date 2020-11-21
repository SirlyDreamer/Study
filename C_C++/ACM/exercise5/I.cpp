#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x,int y)
{
    if (x > y)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int n(0),m(0);
    long long temp(0);
    while(cin >> n >> m)
    {
        long long* number = new long long[n];
        for (int i = 0; i < n; i++)
        {
            cin >> number[i];
        }
        sort(number,number+n,cmp);
        int i(0);
        int num = m;
        for (int i = 0 ; i < m ; i++)
        {
            cout << number[i];
            if (i != m)
                cout << ' ';
        }
        cout << endl;
        delete number;
    }
    return 0;
}