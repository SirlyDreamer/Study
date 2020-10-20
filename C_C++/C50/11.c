#include <stdio.h>
int money[100000] = {0};
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
    temp = money[left];
    while (i!=j)
    {
        while (money[j]<=temp && i<j)
            j--;
        while (money[i]>=temp && i<j)
            i++;
        if (i<j)
            swap(&money[i],&money[j]);
    }
    money[left] = money[i];
    money[i] = temp;
    quicksort (left,i-1);
    quicksort (i+1,right);
    return;
}
int main()
{
    int n = 0,m = 0;
    while (1)
    {
        scanf("%d %d",&n,&m);
        if (m == 0 && n == 0)
            break;
        for (int i = 0;i < n;i++)
            scanf("%d",&money[i]);
        quicksort(0,n);
        for (int i = 0;i < m;i++)
            printf("%d ",money[i]);
        printf("\b\n");
    }
    return 0;
}