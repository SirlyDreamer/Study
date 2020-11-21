#include <iostream>
#include <string>
using namespace std;
bool win(int score1,int score2,int s,bool flag)
{
    if (flag == true)
    {
        if (abs(score1-score2) == 2)
            return true;
    }
    else
    {
        if (score1 == s || score2 == s)
            return true;
    }
    return false;
}
int main()
{
    char temp;
    int score1(0),score2(0);
    string resource;
    bool flag(false);
    while (cin >> temp)
    {
        if (temp != 'E')
            resource = resource + temp;
        else
            break;
    }
    if (resource == "")
        cout << "0:0" << endl << endl << "0:0";
    string::iterator iter = resource.begin();
    while (iter != resource.end())
    {
        score1 = 0;
        score2 = 0;
        flag = false;
        while (!win(score1,score2,11,flag))
        {
            if(*iter == 'W')
            {
                score1++;
                iter++;
            }
            else if(*iter == 'L')
            {
                score2++;
                iter++;
            }
            if(score1 == 10 && score2 == 10)
                flag = true; 
            if (*iter == 'E')
                break;           
        }
        cout << score1 << ':' << score2 << endl;
    }
    iter = resource.begin();
    cout << endl;
    while (iter != resource.end())
    {
        score1 = 0;
        score2 = 0;
        flag = false;
        while (!win(score1,score2,21,flag))
        {
            if(*iter == 'W')
            {
                score1++;
                iter++;
            }
            else if(*iter == 'L')
            {
                score2++;
                iter++;
            }
            if (score1 == 20 && score2 == 20)
                flag = true;
            if (*iter == 'E')
                break; 
        }
        cout << score1 << ':' << score2 << endl;
    }
    return 0;
}