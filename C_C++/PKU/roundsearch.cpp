/*
#include <iostream>
using namespace std;
int main()
{
    int arr[100][100] = {0};
    int row(0),col(0);
    cin >> row >> col;
    for(int i(0);i < row;i++)
        for(int j(0);j < col;j++)
            cin >> arr[i][j];
    int right = col-1;
    int left = 0;
    int down = row-1;
    int up = 0;
    while (right > left && down > up)
    {  
        for(int i = left;i <= right;i++)
            cout << arr[up][i] << endl;
        up++;
        for(int i = up;i <= down;i++)
            cout << arr[i][right] << endl;
        right--;
        for(int i = right;i >= left;i--)
            cout << arr[down][i] << endl;
        down--;
        for(int i = down;i >= up;i--)
            cout << arr[i][left] << endl; 
        left++;
    }
    return 0;
}
*/
#include <iostream>
using namespace std;
 int a[99][99] = { 0 };
int main()
{
    bool flag = true;
    int row, col, i1,i2;//i1是行 i2是列
    cin >> row >> col;//row,i1是行 col,i2是列
    for (i1 = 0; i1 < row; i1++)
        for (i2 = 0; i2 < col; i2++)
            cin >> a[i1][i2];
    i1 = -1; i2 = -1;
    int col1 = col, row1 = row, col2 = 0, row2 = 0;
    while (flag == true)
    {
        i2++;i1++;
        while (i2 < col1)
        {
            cout << a[i1][i2] << endl;
            i2++;
        }
        col1--;

        i1++;i2--;
        while (i1 < row1)
        {
            cout << a[i1][i2] << endl;
            i1++;
        }
        row1--;
        
        i1--;i2--;
        while (i2 >= col2)
        {
            cout << a[i1][i2] << endl;
            i2--;
        }
        col2++;

        i1--;i2++;
        while (i1 > row2)
        {
            cout << a[i1][i2] << endl;
            i1--;
        }
        row2++;

        if (col1 <= col2 || row1 <= row2)//结束
            flag = false;
    }
    return 0;
}