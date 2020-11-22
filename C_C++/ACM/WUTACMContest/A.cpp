#include <iostream>
#include <string>
using namespace std;

int main()
{
    string A,B;
    int ans(0);
    cin >> A >> B;
    ans = A.find(B);
    if(ans == string::npos)
        return 0;
    A.erase(0,ans+1);
    ans += A.find(B)+2;
    cout << ans;
    return 0;
}