#include <iostream>
#include <string>
using namespace std;
int main()
{
    string selfintroduce;
    int n(0),max(0),sum(0);
    cin >> n;
    while(n--)
    {
        max = 0;
        sum = 0;
        cin >> selfintroduce;
        for(string::iterator a = selfintroduce.begin();a < selfintroduce.end();a++)
        {
            if (*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u')
            {
                sum ++;
                if (max < sum)
                    max = sum;
            }
            else
            {
                sum = 0;
            }
        }
        cout << max << endl;
    }
    return 0;
}