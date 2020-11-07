#include <iostream>
#include <string>
using namespace std;

int main()
{
    int c;
    string a,b,sc;
    getline(cin,a,'.');
    getline(cin,b,'e');
    getline(cin,sc);
    c = atoi(sc.c_str());
    if (b == "0" && c == 0)
    {
        cout << a;
        return 0;
    }
    if (a == "0")
    {
        if (c == 0)
        {
            cout << "0."+b;
            return 0;
        }
        if (b.size() == c)
        {
            b.erase(0,b.find_first_not_of('0'));
            cout << b;
            return 0;
        }
        if (b.size() < c)
        {
            string result = b;
            result.resize(c,'0');
            result.erase(0,result.find_first_not_of('0'));
            cout << result;
            return 0;
        }
        if (b.size() > c)
        {
            b.insert(c,1,'.');
            b.erase(0,b.find_first_not_of('0')-1);
            cout << b;
            return 0;
        }
    }
    if (b.size() == c)
    {
        cout << a+b;
        return 0;
    }
    if (b.size() < c)
    {
        string result = a+b;
        result.resize(a.size()+c,'0');
        result.erase(0,result.find_first_not_of('0'));
        cout << result;
        return 0;
    }
    if (b.size() > c)
    {
        b.insert(c,1,'.');
        cout << a+b;
        return 0;
    }
    return 0;
}