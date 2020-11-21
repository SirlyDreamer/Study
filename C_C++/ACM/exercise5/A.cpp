#include <iostream>
#include <string>
using namespace std;

string add(string s1, string s2)
{
	int sum[512] ={0}, a[512] = {0}, b[512] = {0};
	int len1 = s1.length(),len2 = s2.length();
	for(int i=1; i<=len1; i++)
        a[i] = s1[len1 - i] - '0';
	for(int i=1; i<=len2; i++)
        b[i] = s2[len2 - i] - '0';
	int lens = max(len1,len2);
	for(int i=1; i<=lens; i++)
	{
		sum[i] += a[i] + b[i];
		sum[i+1] += sum[i]/10;
		sum[i] %= 10;
	}
	while(sum[lens+1] != 0)
        lens++;
	string ans;
	for(int i=lens; i>=1; i--)
        ans += sum[i] + '0';
	return ans;
}

int main()
{
    string a,b;
    while (cin >> a >> b)
        cout << add(a,b) << endl;
    return 0;
}