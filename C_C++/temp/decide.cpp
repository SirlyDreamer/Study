#include<iostream>
using namespace std;
int main()
{
    for (int a = 1; a < 100; a++)
        for (int b = 1; b < 100; b++)
            for (int c = 1; c < 100; c++)
                for (int d = 1; d < 100; d++)
                    for (int f = 1; f < 100; f++)
                        if (23*a+24*b+67*c+45*d+34*f == 1000)
                            cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << f << endl;
    return 0;
}