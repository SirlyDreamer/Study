#include <iostream>
using namespace std;
int main()
{
    int l = 0,m = 0;
    int u = 0,v = 0;
    int sum = 0;
    bool noTree[10000] = {false};

    cin >> l >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        for (int j = u; j <= v; j++)
            noTree[j] = true;
    }

    for (int i = 1; i <= l; i++)
        if(noTree[i] == false)
            sum ++;

    cout << sum << endl;
    return 0;
}