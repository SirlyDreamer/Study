#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float y(0);
    char graph[27][65] = {' '};
    for (int i(0);i < 65;i ++)
        graph[14][i] = '-';
    for (int x(0);x < 65;x ++)
    {
        y = 13*sin(x) + 13;
        graph[x][(int)y] = '-';
        y = 13*cos(x) + 13;
        graph[x][(int)y] = '-';
    }
    for (int i(27);i >= 0;i--)
    {
        for (int j(0);j < 65;j++)
            cout << graph[i][j];
        cout << endl;
    }
    return 0;
}