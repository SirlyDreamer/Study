#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int x[10] = {0}, y[10] = {0}, z[10] = {0};//坐标
    double d[100] = { 0 }, d1[10][10] = { 0 };//距离
    int n, m(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    for (int i = 0; i < n; i++)
    {
        for (int i1 = 0; i1 < n; i1++)
        {
            if (i1 <= i)
                continue;
            else
            {
                int x1 = x[i] - x[i1], y1 = y[i] - y[i1], z1 = z[i] - z[i1];
                d[m] = sqrt(x1 * x1 + y1 * y1 + z1 * z1);//距离
                d1[i][i1] = d[m];
                m++;
            }
        }
    }
    double d2[100];
    bool flag1 = true;
    for (int i = 0; i < m; i++)
        d2[i] = d[i];//距离数组d复制一遍
    sort(d2, d2 + m);//距离从小到大排序
    for (int i = m - 1; i >= 0; i--)
    {
        flag1 = true;
        for (int i1 = 0; i1 < n; i1++)
        {
            if (flag1 == false)
                break;
            for (int i2 = 0; i2 < n; i2++)
                if (d1[i1][i2] == d2[i])
                {
                    cout << '(' << x[i1] << ',' << y[i1] << ',' << z[i1] << ")-(" << x[i2] << ',' << y[i2] << ',' << z[i2] << ")=";
                    cout << fixed << setprecision(2) << d2[i] << endl;
                    d1[i1][i2] = 0;
                    flag1 = false;
                    break;
                }
        }
    }
    return 0;
}