#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct option
{
    int op;
    double angle;
    double dx;
    double dy;
};

int main()
{
    struct option ops[50005] = {{0,0,0,0}};
    double x(0),y(0),dx(0),dy(0);
    int op(0);
    double angle(0);
    int N(0),T(0);
    int a(0),b(0);
    cin >> N >> T;
    for (int i(1);i<=N;i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> dx >> dy;
            ops[i].op = op;
            ops[i].dx = dx;
            ops[i].dy = dy;
        }
        else
        {
            cin >> angle;
            ops[i].op = op;
            ops[i].angle = angle;
        }
    }
    while(T--)
    {
        cin >> a >> b;
        x = 0;
        y = 0;
        for (int i(a);i <= b;i++)
        {
            if(ops[i].op == 1)
            {
                x = x + ops[i].dx;
                y = y + ops[i].dy;
            }
            else
            {
                dx = x*cos(ops[i].angle*M_PI/180) - y*sin(ops[i].angle*M_PI/180);
                dy = x*sin(ops[i].angle*M_PI/180) + y*cos(ops[i].angle*M_PI/180);
                x = dx;
                y = dy;
            }
        }
        cout << setiosflags(ios::showpoint) << fixed << setprecision(3) << x << ' ' << y << endl;
    }
    return 0;
}