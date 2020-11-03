#include<iostream>
using namespace std;
int main()
{
    for (int a = 3; a < 100; a++)
        for (int b = 3; b < 100; b++)
            for (int c = 3; c < 100; c++)
                for (int d = 3; d < 100; d++)
                    for (int f = 3; f < 100; f++)
                        if (23*a+24*b+67*c+45*d+34*f == 1000)
                            cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << f << endl;
    return 0;
}