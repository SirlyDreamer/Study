#include <iostream>
#include <string>
using namespace std;

char check(string ISBN)
{
    int sum = 0;
    int i(1);
    for (string::iterator num = ISBN.begin();num < ISBN.end()-2;num++)
    {
        if (*num == '-')
            num++;
        sum += (*num-'0')*i;
        i++;
    }
    sum = sum%11;
    if (sum == 10)
        return 'X';
    else
        return (char)(sum +'0');
    
}

int main()
{
    string ISBN;
    cin >> ISBN;
    char checksum = check(ISBN);
    string::iterator tail = ISBN.end() - 1;
    if (*tail == checksum)
        cout << "Right";
    else
    {
        *tail = checksum;
        cout << ISBN;
    }
    return 0;
}