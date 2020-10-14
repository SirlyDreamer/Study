#include <cstdio>
using namespace std;
int main()
{
    int n = 0;
    bool f1 = false,f2 = false;
    scanf("%d",&n);
    if (n%2 == 0)
        f1 = true;
    if (n > 4 && n <= 12)
        f2 = true;
    printf("%d %d %d %d",f1 && f2,f1 || f2,(f1 || f2) && !(f1 && f2),!(f1 || f2));
    return 0;
}