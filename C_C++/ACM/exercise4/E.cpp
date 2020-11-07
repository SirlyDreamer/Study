#include <iostream>
#include <cmath>
using namespace std;

int S(long long int num)
{
    int s(0);
    while(num != 0)
    {
        s += num % 10;
        num /= 10;
    }
    return s;
}

int main()
{
    long long int num(0),maxsub9x(0);
    int digit(0);
    int result(0);
    cin >> num;
    maxsub9x = pow(10,(int)log10(num))-1;
    result = 9*(int)log10(num) + S(num-maxsub9x);
    cout << result;
    return 0;
}