#include <cstdio>
using namespace std;
int arr[100]={0};
void swap(int *pa,int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}
void quicksort(int left,int right)
{
    if (left>right)
        return;
    int i,j,t,temp;
    i = left;
    j = right;
    temp = arr[left];
    while (i!=j)
    {
        while (arr[j]<=temp && i<j)
            j--;
        while (arr[i]>=temp && i<j)
            i++;
        if (i<j)
            swap(&arr[i],&arr[j]);
    }
    arr[left] = arr[i];
    arr[i] = temp;
    quicksort (left,i-1);
    quicksort (i+1,right);
    return;
}
int main()
{
    int i,n;
    scanf ("%d",&n);
    for (i=0;i<n;i++)
        scanf ("%d",&arr[i]);
    quicksort(0,n-1);
    for (i=0;i<n;i++)
        printf ("%d  ",arr[i]);
    return 0;
}