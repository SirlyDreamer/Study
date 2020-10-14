#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool a(false);
    int x(1);
    int m(0);
    do
    { 
        x++;
        for (int i(2); i < x; i++)
            if (x % i == 0)
                a = false;
            else
                a = true;
        if (a == true && n % x == 0)
        {
                while (n % x == 0)
                {
                    n = n / x;
                    m++;
                }
                cout << x << " " << m << endl;
                m = 0;
            
        }
    } while (n != 1);
    return 0;
}