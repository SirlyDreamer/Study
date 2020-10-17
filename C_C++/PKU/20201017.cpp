#include <iostream>
using namespace std;
int main()
{
    char key;
    while (cin >> key)
    {
        if ((65 <= (int)key && (int)key <= 90 )|| (97 <= (int)key && (int)key <= 122))
        {
            if ((int)key > 90)
                key = key - 32;
            int times = (int)key - int('A');
            int i = 0, k = times;
            while (i <= times)
            {
                for (int m = 1; m <= k; m++)
                    cout << ' ';                      
                for (int n = 0; n <= i; n++)
                    cout << (char)('A' + n);         
                for (int mn = i - 1; mn >= 0; mn--)
                    cout << (char)('A' + mn);
                cout << endl;
                i++;
                k--;
            }
        }
        else
        {
            cout << "invalid character!" << endl;
            cin.ignore();
        }
    }
    return 0;
}
