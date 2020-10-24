#include <iostream>
#include <cmath>
using namespace std;
int getDigit(int number,int i)
{
    return number / (int)pow(10,i) % 10;
}
int main()
{
    int i(0);
    cin >> i;
    if (pow(getDigit(i,0),3)+pow(getDigit(i,1),3)+pow(getDigit(i,2),3) == i)
        cout << 'Y';
    else
        cout << 'N';
    return 0;
}