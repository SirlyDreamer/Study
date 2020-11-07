#include <iostream>
using namespace std;

void Hanoi(int n,char from,char throth,char to)
{
    if (n == 1)
    {
        cout << n << ":" << from << "->"<< to << endl;
        return;
    }
    Hanoi(n-1,from,to,throth);
    cout << n << ":" << from << "->"<< to << endl;
    Hanoi(n-1,throth,from,to);
    return;
}

int main()
{
    int num(0);
    char a(0),b(0),c(0);
    cin >> num >> a >> b >> c;
    Hanoi(num,a,b,c);
    return 0;
}