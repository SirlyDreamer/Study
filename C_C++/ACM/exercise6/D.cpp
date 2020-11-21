#include <iostream>
using namespace std;

long long apowbmodm(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int N(0),A(0),B(0),C(0);
    cin >> N;
    while(N--)
    {
        cin >> A >> B >> C;
        cout << apowbmodm(A,B,C) << endl;
    }
    return 0;
}