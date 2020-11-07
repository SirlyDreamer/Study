#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Haab{
    unordered_map<string,int> months ={ {"pop",0},{"no",1},{"zip",2},{"zotz",3},{"tzec",4},{"xul",5},{"yoxkin",6},{"mol",7},{"chen",8},{"yax",9},{"zac",10},{"ceh",11},{"mac",12},{"kankin",13},{"muan",14},{"pax",15},{"koyab",16},{"cumhu",17},{"uayet",18} };
    string month;
    int day;
    int year;
};

struct Tzolkin{
    string days[20] = {"ahau","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac"};
    int day;
    int year;
};

struct Tzolkin HaabToTzolkin(struct Haab *Haab)
{
    int day = (Haab->year)*365 + (Haab->months.at(Haab->month))*20 + Haab->day;
    struct Tzolkin result;
    result.year = (day+1)/260;
    result.day = (day+1)%260;
    if (result.day == 0)
        result.year--;
    return result;
}

int main()
{
    struct Haab haab;
    struct Tzolkin tzolkin;
    int num(0);
    cin >> num;
    cout << num << endl;
    char dustbin;
    for (int i = 0; i < num; i++)
    {
        cin >> haab.day >> dustbin >> haab.month >> haab.year;
        tzolkin = HaabToTzolkin(&haab);
        if (tzolkin.day%13 == 0)
            cout << 13 << ' ' << tzolkin.days[tzolkin.day%20] << ' ' << tzolkin.year << endl;
        else
            cout << tzolkin.day%13 << ' ' << tzolkin.days[tzolkin.day%20] << ' ' << tzolkin.year << endl;
    }
    return 0;
}