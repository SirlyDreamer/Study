#include <stdio.h>
int Score[50][5];
double getAverageScore(int s,int place,int length)
{
    double sum = 0,avr = 0;
    switch (s)
    {
    case 0:
        for (int i;i < length;i++)
            sum += Score[i][place];
        avr = sum / length;
        return avr;
        break;
    case 1:
        for (int i;i < length;i++)
            sum += Score[place][i];
        avr = sum / length;
        return avr;
        break;
    default:
        break;
    }
}
int main()
{
    int m = 0,n = 0;
    int mavr[5] = {0};
    int sum = 0;
    scanf("%d %d",&n,&m);
    for(int student = 0;student < n;student ++)
        for(int score = 0;score < m;score++)
            scanf("%d",&Score[student][score]);
    for(int student = 0;student < n;student++)
        printf("%.2f",getAverageScore(1,i,n));
    for(int student = 0;student < n;student++)
        mavr[student] = getAverageScore(0,i,n);
    for(int score = 0;score < m;score++)
        printf("%d",mavr[score]);
    for(int score = 0;score < m;score++)
        if (mavr[score][1])

    scanf
}