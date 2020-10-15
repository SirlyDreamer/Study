#include <iostream>
#include <cmath>
using namespace std;
void swap (int* a,int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void QuickSort(int* arr,int* absarr,int left,int right)
{
    if (left > right)
        return;
    int i = left,j = right;
    int temp = arr[left];
    int abstemp = absarr[left];
    while (i != j)
    {
        while (absarr[j] <= abstemp && i<j)
            j--;
        while (absarr[i] >= abstemp && i<j)
            i++;
        if (i<j)
        {
            swap(&absarr[i],&absarr[j]);
            swap(&arr[i],&arr[j]);
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;
    absarr[left] = absarr[i];
    absarr[i] = abstemp;
    QuickSort(arr,absarr,left,i-1);
    QuickSort(arr,absarr,i+1,right);
    return;
}
int main()
{
    int arr[10][101] = {0};
    int n[10] = {0};
    int i(-1);
    int temp[100] = {0};
    int abstemp[100] = {0};
    do
    {
        i++;
        cin >> n[i];
        for (int j(0) ; j<n[i] ; j++)
            cin >> temp[j];
        for (int j(0) ; j<n[i] ; j++)
            abstemp[j] = abs(temp[j]);
        QuickSort(temp,abstemp,0,n[i]);
        for (int j(0) ; j<n[i] ; j++)
            arr[i][j] = temp[j];
    }while (n[i] != 0);
    for (int x(0) ; x < i ; x++)
    {
        for (int y(0) ; y < n[x] ; y++)
            cout << arr[x][y] << ' ';
        cout << '\b' << endl;
    }
    return 0;
}