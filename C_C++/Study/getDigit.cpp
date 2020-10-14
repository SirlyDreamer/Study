#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int number(0),n(0);
    cin >> n >> number;
    int *digit = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        digit[i] = number / (int)pow(10,i) % 10;
        cout << digit[i] << "    ";
    }
    return 0;
}