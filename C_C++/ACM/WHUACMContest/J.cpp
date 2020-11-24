#include <cstdio>
using namespace std;
int main()
{
    int n(0),a(0),k(0);
    int hp[1005] = {0};
    int end(0);
    int choose(0);
    int killed(0);
    scanf("%d%d%d",&n,&a,&k);
    for (int i(0);i < n;i++)
        scanf("%d",&hp[i]);
    for (int i(0);i < n;i++)
    {
        if (hp[i] > k)
        {
            end = i;
        }
    }
    for (int i(n-1);i >= 0;i--)
    {
        if 
    }
    printf("%d",killed);
    return 0;
}