#include <iostream>
using namespace std;

int eatPeach(int day)
{
    if (day == 1)
        return 1;
    return 2*(eatPeach(day-1) + 1);
}

int main()
{
    int day(0);
    while (cin >> day)
        cout << eatPeach(day) << endl;
    return 0;
}