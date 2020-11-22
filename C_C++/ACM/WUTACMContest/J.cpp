#include <iostream>
using namespace std;
int weight[100000] = {0};
int ask(int i)
{
    int n(1),num(0);
    while(n*i <= 100000)
    {
        num += weight[n*i];
        n++;
    }
    return num;
}
int main()
{
    int n(0),a(0);
    int sum(0);
    cin >> n;
    while(n--)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> a;
            weight[a] ++;
        }
        else
        {
            cin >> a;
            sum += ask(a);
        }
    }
    cout << sum;
    return 0;
}