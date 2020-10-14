#include <stdio.h>
#include <stdlib.h>
int *tree;
void cutTree(int left,int right)
{
    for (int i = left; i <= right; i++)
        tree[i] = 0;
}
int main()
{
    int l = 0,m = 0;
    int u = 0,v = 0;
    int sum = 0;
    scanf("%d %d",&l,&m);
    tree = (int*)malloc(l*sizeof(int));
    for (int i = 0; i <= l; i++)
        tree[i] = 1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        cutTree(u,v);
    }
    for (int i = 0; i <= l; i++)
        if(tree[i] == 1)
            sum ++;
    printf("%d",sum);
    return 0;
}