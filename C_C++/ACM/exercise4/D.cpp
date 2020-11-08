#include <iostream>
using namespace std;

bool judgeSkyNumber(int num)
{
    int OCT = num;
    int HEX = num,HEXsum(0);
    int DEC = num,DECsum(0);
    int sum(0);
    while(OCT != 0)
    {
        sum += OCT % 10;
        OCT /= 10;
    }
    while(HEX != 0)
    {
        HEXsum += HEX % 16;
        HEX /= 16;
    }
    if (HEXsum != sum)
        return false;
    while(DEC != 0)
    {
        DECsum += DEC % 12;
        DEC /= 12;
    }
    if (DECsum != sum)
        return false;
    return true;
}

int main()
{
    int num(0);
    while(cin >> num)
    {
        if (num == 0)
            break;
        if (judgeSkyNumber(num))
            cout << num << " is a Sky Number." << endl;
        else
            cout << num << " is not a Sky Number." << endl;
    }
    return 0;
}