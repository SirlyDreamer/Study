#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory.h>
using namespace std;

unordered_map<int,vector<int>*> gugu;
int line[100005] = {0};

int main()
{
    int range;
    cin >> range;
    int kind(0);
    for(int i(0);i < range;i++)
    {
        cin >> kind;
        if (gugu.find(kind) == gugu.end())
        {
            vector<int> *place = new vector<int>;
            place->push_back(i);
            gugu.emplace(kind,place);
        }
        else
        {
            vector<int>* place = gugu.at(kind);
            place->push_back(i);
        }
        line[i] = kind;
    }
    for(int i(0);i < range;i++)
    {    
        int kind = line[i];
        vector<int> *places = gugu.at(kind);
        int dis(1000000);
        if (places->size() == 1)
            dis = -1;
        else
        {
            vector<int>::iterator left = places->begin();
            vector<int>::iterator right = places->end();
            vector<int>::iterator iter = left + (right - left)/2;
            while(left < right && *iter == i)
            {
                if (*iter > i)
                    right = iter;
                else if(*iter < i)
                    left = iter + 1;
                iter = left + (right - left)/2;
            }
            if (*iter-*(iter-1) > *(iter+1)-*iter)
                dis = *(iter+1)-*iter;
            else
                dis = *iter-*(iter-1);
        }
        cout << dis << ' ';
    }
    return 0;
}