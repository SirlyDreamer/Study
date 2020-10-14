#include <stdio.h>
char field[241][241] = {'*'};
void plowField(int x1,int y1,int x2,int y2)
{
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            field[i][j] = '#';
}
int main()
{
    int x,y,n = 0,sum =0;
    int x1,x2,y1,y2;
    scanf("%d %d %d",&x,&y,&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        plowField(x1,y1,x2,y2);
    }
    for (int i = 0; i <= 240; i++)
        for (int j = 0; j <= 240; j++)
            if (field[i][j] == '#')
                sum ++;
    printf("%d",sum);
    return 0;
}