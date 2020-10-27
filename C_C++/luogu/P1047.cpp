#include <iostream>
using namespace std;
int main()
{
    int l = 0,m = 0;
    int u = 0,v = 0;
    int sum = 0;
    bool tree[10000] = {false};
    cin >> l >> m;
    for (int i = 0; i <= l; i++)
        tree[i] = true;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        for (int i = u; i <= v; i++)
            tree[i] = false;
    }
    for (int i = 0; i <= l; i++)
        if(tree[i] == true)
            sum ++;
    cout << sum;
    return 0;
}