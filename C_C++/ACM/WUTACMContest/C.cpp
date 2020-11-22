#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n(0);
    int a(0),b(0),c(0),ans(0);
    string aa,bbb,ccc;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        aa = to_string(a)+to_string(a);
        bbb = to_string(b)+to_string(b)+to_string(b);
        ccc = to_string(c)+to_string(c)+to_string(c);
        ans = atoi(aa.c_str()) + atoi(bbb.c_str()) + atoi(ccc.c_str());
        cout << ans << endl;
    }
    return 0;
}