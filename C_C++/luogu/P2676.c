#include <stdio.h>
int H[20000]={0};
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
    temp = H[left];
    while (i!=j)
    {
        while (H[j] <= temp && i < j)
            j--;
        while (H[i] >= temp && i < j)
            i++;
        if (i < j)
            swap(&H[i],&H[j]);
    }
    H[left] = H[i];
    H[i] = temp;
    quicksort (left,i-1);
    quicksort (i+1,right);
    return;
}
int main()
{
    int N = 0,B = 0,sum = 0,height = 0;
    scanf ("%d %d",&N,&B);
    for (int i=0;i<N;i++)
        scanf ("%d",&H[i]);
    quicksort(0,N-1);
    for (int i=0 ; i<N ; i++)
    {
        height += H[i];
        if (height >= B)
        {
            sum = i+1;
            break;
        }
    }
    printf ("%d",sum);
    return 0;
}