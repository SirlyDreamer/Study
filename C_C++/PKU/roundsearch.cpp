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