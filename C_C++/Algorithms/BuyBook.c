#include <stdio.h>
#include <stdlib.h>
void quicksort(int left,int right,int ISBN[])
{
    if (left > right)
        return;
    int i,j,t,temp;
    i = left;
    j = right;
    temp = ISBN[left];
    while (i!=j)
    {
        while (ISBN[j]>=temp && i<j)
            j--;   
        while (ISBN[i]<=temp && i<j)
            i++;
        if (i<j)
        {
            t = ISBN[i];
            ISBN[i] = ISBN[j];
            ISBN[j] = t;
        }
    }
    ISBN[left] = ISBN[i];
    ISBN[i] = temp;
    quicksort(left,i-1,ISBN);
    quicksort(i+1,right,ISBN);
    return;
}
int main()
{
    int i,n;
    printf("Please input the sum of books:");
    scanf("%d",&n);
    int *ISBN = (int*)malloc(n*sizeof(int));
    printf("\nPlease input the ISBN of each book:\n");
    for (i=0;i<n;i++)
        scanf("%d",&ISBN[i]);
    quicksort(0,n-1,ISBN);
    for (i=0;i<n;i++)
        printf("ISBN:%d\n",ISBN[i]);
    return 0;
}