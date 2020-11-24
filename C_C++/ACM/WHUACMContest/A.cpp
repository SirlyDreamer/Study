#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
pair<int,double> s;
map<pair<int,double>,bool> failed;
int total(0);
double dishPrice[105] = {0.0};
bool dishPicked[105] = {false};
bool valid(false);
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(double balance,int step)
{
    s.first = step;
    s.second = balance;
    if (valid == true)
        return;
    if (step > 2 && failed.find(s) != failed.end())
    	return;
    if (step > total)
    {
        printf("yes\n");
        valid = true;
        return;
    }
    for(int i(0);i < total;i++)
    {
        if (dishPicked[i] == false && balance >= dishPrice[i])
        {
            balance -= 0.7*dishPrice[i];
            dishPicked[i] = true;
            dfs(balance,step+1);
            dishPicked[i] = false;
        }
    }
    if (step > 2)
    {
        failed.emplace(s,true);
        return;
    }
}
int main()
{
    int T(0);
    double balance(0);
    double all(0);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %lf",&total,&balance);
        all = 0;
        for(int i(0);i < total;i++)
        {
            scanf("%lf",&dishPrice[i]);
            all += dishPrice[i];
        }
        if (all*0.7 > balance)
            printf("no\n");
        else
        {
            valid = false;
            sort(dishPrice,dishPrice + total,cmp);
            dfs(balance,1);
            if(valid == false)
                printf("no\n");
        }
        failed.clear();
    }
    return 0;
}