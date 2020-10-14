#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int y(0);
    char graph[27][65]{' '};
    for (int i(0);i < 27;i ++)
    {
        for (int j(0);j < 65;j++)
        {
            if (i == 14)    
                graph[i][j] = '-';
            else
                graph[i][j] = ' ';
        }
    }
    for (int x(0);x < 65;x ++)
    {
        y = (int)(13.0*sin(x) + 13.0);
        graph[x][y] = '*';
        y = (int)(13.0*cos(x) + 13.0);
        graph[x][y] = '*';
    }
    for (int i(27);i >= 0;i--)
    {
        for (int j(0);j < 65;j++)
            cout << graph[i][j];
        cout << endl;
    }
    return 0;
}