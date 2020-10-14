#include <iostream>
using namespace std;
int main()
{
    int number(0);
    bool flag(true);
    cin >> number;
    for (int i = 2; i <= number/2; i++)
        if (number % i == 0)
            flag = false;
    if (flag)
        cout << number << " is a prime number!" << endl;
    else
        cout << number << " is not a prime number" << endl;
    return 0;
}