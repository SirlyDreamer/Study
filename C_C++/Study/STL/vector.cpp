#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int data(0);
    vector<int> arr;
    while(cin >> data)
        arr.push_back(data);
    for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
        cout << *iter << ' ';
    return 0;
}