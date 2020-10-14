#include <iostream>
using namespace std;
int main()
{
    char people[6] = {'0','0','0','0','0','0'};
    for (int z(1); z <= 5; z++)
    {
        for (int q(1); q <= 5; q++)
        {
            for (int s(1);s <= 5;s++)
            {
                for (int l(1); l <= 5; l++)
                {
                    if (z == q || z == s || z == l || q == s || q == l || s == l)
                        continue;
                    if (((z + q) == (s + l))&&((z + l) > (s + q))&&((z + s) < q))
                    {
                        people[z] = 'z';
                        people[q] = 'q';
                        people[s] = 's';
                        people[l] = 'l';
                        break;
                    }    
                }
            }
        }
    }
    for (int i(5) ; i > 0 ; i--)
        if (people[i] != '0')
            cout << people[i] << ' ' << i*10 << endl;
    return 0;
}