#include <iostream>
using namespace std;
int array[99][99] = { 0 };
int main()
{
    int row, col, i1,i2;
    cin >> row >> col;//row,i1是行 col,i2是列
    for (i1 = 0; i1 < row; i1++)
        for (i2 = 0; i2 < col; i2++)
            cin >> array[i1][i2];
    i1 = 0; i2 = 0;
    int col1 = col, row1 = row, col2 = 0, row2 = 0;
    while (true)
    {
        for (i2 = i2; i2 < col1; i2++)
            cout << array[i1][i2] << endl;
        for (i1 = i1 + 1; i1 < row1; i1++)
            cout << array[i1][i2] << endl;
        for (i2 = i2 - 1; i2 >= col2; i2--)
            cout << array[i1][i2] << endl;
        for (i1 = i1 - 1; i2 >= row2 + 1; i2--)
            cout << array[i1][i2] << endl;
        col1--; row1--; col2--; row2--;
        if (col1 <= col2 || row1 <= row2)
            break;
    }
    return 0;
}
