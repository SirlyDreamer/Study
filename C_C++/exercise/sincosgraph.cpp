#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int y(0);
    char graph[128][27];
    for (int i(0);i < 128;i ++)
    {
        for (int j(0);j < 27;j++)
        {
            if (j == 13)
                graph[i][j] = '-';
            else
                graph[i][j] = ' ';
        }
    }
    for (int x(0);x < 128;x ++)
    {
        y = (int)(13.0*sin(x/20.0) + 13.0);
        graph[x][y] = '*';
        y = (int)(13.0*cos(x/20.0) + 13.0);
        graph[x][y] = '*';
    }
    for (int j(0);j < 27;j++)
    {
        for (int i(127);i >= 0;i--)    
            cout << graph[i][j];
        cout << endl;
    }
    return 0;
}