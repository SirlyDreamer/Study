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
            for(vector<int>::iterator iter = places->begin();iter < places->end();iter++)
            {
                if (*iter != i && dis > abs(*iter - i))
                    dis = abs(*iter - i);
            }
        }
        cout << dis << ' ';
    }
    return 0;
}