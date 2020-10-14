#include <iostream>
using namespace std;
int main()
{
    int x(1), y, z;
    int a, b, c;
    int temp;
    int A, B, C;
    while (!(a == C && b == B && c == A))
    {
        a = x % 7; temp = x/7;
        b = temp % 7; temp /= 7;
        c = temp % 7;

        A = x % 9; temp = x / 9; 
        B = temp % 9; temp /= 9; 
        C = temp % 9;

        x++;
    }
    y = 100 * c + 10 * b + a;
    z = 100 * C + 10 * B + A;
    int sign;
    cin >> sign;
    switch (sign)
    {
        case 1:
            cout << x;
            break;
        case 2:
            cout << y;
            break;
        case 3:
            cout << z;
            break;
        default:
            break;
    }
    return 0;
}