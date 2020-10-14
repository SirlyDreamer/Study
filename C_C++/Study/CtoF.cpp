#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n(1);              //初始化n为0
    cin >> n;
    double C[n];
    double F[n];
    for (int i = 0; i < n; i++)
    {
        C[i] = F[i] = 0;//动态数组初始化(也可不用)
        cin >> F[i];
        C[i] = 5*(F[i]-32)/9;
    }
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(5) << C[i] << endl;//中间一大坨是设置保留小数位数，要用的话要在代码前面加上 #include <iomanip>
    return 0;
}