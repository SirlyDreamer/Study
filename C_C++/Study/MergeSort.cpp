#include <iostream>
using namespace std;
void mergeSort(int head,int tail,int *arr,int *temp)
{
    if (tail == head)
        return;
    int middle = (tail + head)/2;
    mergeSort(head,middle,arr,temp);
    mergeSort(middle+1,tail,arr,temp);
    int *ptemp;
    ptemp = &temp[head];
    int *parr1,*parr2;
    parr1 = &arr[head];
    parr2 = &arr[middle+1];
    while (parr1 <= &arr[middle] && parr2 <= &arr[tail])
    {
        if (*parr1 <= *parr2)
            *ptemp++ = *parr1++;
        else
            *ptemp++ = *parr2++;
    }
    while (parr1 <= &arr[middle])
        *ptemp++ = *parr1++;
    while (parr2 <= &arr[tail])
        *ptemp++ = *parr2++;
    for (int i = head; i <= tail ; i++)
        arr[i] = temp[i];
}
int main()
{
    int n = 0;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int *temp = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    mergeSort(0,n-1,arr,temp);
    for (int i = 0; i < n; i++)
        printf("%d  ",arr[i]);
    return 0;
}