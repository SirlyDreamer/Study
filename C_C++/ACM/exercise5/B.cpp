#include <iostream>
#include <string>
using namespace std;

string switchsn(unsigned int number,int sn)
{
    string result = "";
    while (number > 0)
    {
        result = (char)((number%sn)+'0') + result;
        number /= sn;
    }
    return result;
}

int main()
{
    unsigned int a(0),b(0);
    int m(0);
    while (cin >> m)
    {
        if (m == 0)
            break;
        cin >> a >> b;
        if (a == 0 && b == 0)
            cout << "0" << endl;
        else
            cout << switchsn(a+b,m) << endl;
    }
    return 0;
}