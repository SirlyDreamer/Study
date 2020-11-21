#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    int score;
};

bool cmp(struct student s1,struct student s2)
{
    if(s1.score > s2.score)
        return true;
    else
        return false;
}

bool isError(struct student* standard,struct student* target,int sum)
{
    for (int i = 0; i < sum; i++)
        if(standard[i].score != target[i].score)
            return true;
    return false;
}

bool isStable(struct student* standard,struct student* target,int sum)
{
    for (int i = 0; i < sum; i++)
        if(standard[i].name != target[i].name)
            return false;
    return true;
}

int main()
{
    int N(0);
    struct student* students = new student[300];
    struct student* result = new student[300];
    while(cin >> N)
    {
        for (int i = 0; i < N; i++)
            cin >> students[i].name >> students[i].score;
        for (int i = 0; i < N; i++)
            cin >> result[i].name >> result[i].score;
        stable_sort(students,students+N,cmp);
        if (isError(students,result,N))
        {
            cout << "Error" << endl;
            for (int i = 0; i < N; i++)
                cout << students[i].name << ' ' << students[i].score << endl;
        }
        else if (!isStable(students,result,N))
        {
            cout << "Not Stable" << endl;
            for (int i = 0; i < N; i++)
                cout << students[i].name << ' ' << students[i].score << endl;
        }
        else
            cout << "Right" << endl;
    }
    return 0;
}