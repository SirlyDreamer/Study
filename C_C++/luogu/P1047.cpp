#include <iostream>
using namespace std;
bool noTree[10000]{false};
void cutTree(int left,int right)
{
    for (int i = left; i <= right; i++)
        noTree[i] = true;
    return;
}
int main()
{
    int l = 0,m = 0;
    int u = 0,v = 0;
    int sum = 0;
    cin >> l >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cutTree(u,v);
    }
    for (int i = 0; i <= l; i++)
        if(noTree[i] == false)
            sum ++;
    cout << sum << endl;
    return 0;
}