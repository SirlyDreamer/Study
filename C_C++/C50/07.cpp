#include <iostream>
using namespace std;
void multiOddNumber()
{
    int n(0),num(0),multi(1);
    cin >> n;
    for (int i(0);i<n;i++)
    {
        cin >> num;
        if (num  % 2 != 0)
            multi *= num;
    }
    cout << multi << endl;
}
int main()
{
    int n,i,sum;
    while (true)
        multiOddNumber();
    return 0;
}