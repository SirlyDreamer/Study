#include <iostream>
#include <cmath>
using namespace std;

int Frame(int n)
{
    int r = (sqrt(8*n+1)-1)/2;
    return (n-(pow(r,2)-r+2)/2)*pow(2,r)+1;
}

int main()
{
    int num(0);
    while(cin >> num)
        cout << Frame(num) << endl;
    return 0;
}