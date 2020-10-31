#include <iostream>
#include <algorithm>

using namespace std;

int user[100][101] = {0};

int max()
{
    int max = user[0][0],index(0);
    for (int i(1);i < 100;i++)
    {
        if (max < user[i][0])
        {
            max = user[i][0];
            index = i;
        }
    }
    return index;
}

int main()
{
    int N(0);
    int a(0),k(0),b(0);
    cin >> N;
    for (int i;i < N;i++)
    {
        cin >> a >> k;
        for (int j;j < k;j++)
        {
            cin >> b;
            user[b][0]++;
            user[b][1]++;
            user[b][user[b][1]+1] = a;
        }
    }
    int MPU = max();
    cout << MPU << endl;
}