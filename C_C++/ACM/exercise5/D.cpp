#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
using namespace std;

struct user
{
	string name;
	int Score;
	int Penalty;
};

bool cmp(struct user s1, struct user s2)
{
	if (s1.Score > s2.Score)
		return true;
	else if (s1.Score < s2.Score)
		return false;
	else if (s1.Penalty < s2.Penalty)
		return true;
	else if (s1.Penalty > s2.Penalty)
		return false;
	else if (s1.name < s2.name)
		return true;
	else
		return false;
}

struct user process(string* data, int n, int m)
{
	int a(0), b(0);
	struct user result;
	result.name = data[0];
	result.Score = 0;
	result.Penalty = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (data[i].find('(') != data[i].npos)
		{
			sscanf(data[i].c_str(), "%d(%d)", &a, &b);
			result.Score++;
			result.Penalty += (a + m * b);
		}
		else
		{
			a = atoi(data[i].c_str());
			if (a > 0)
			{
				result.Score++;
				result.Penalty += a;
			}
		}
	}
	return result;
}

int main()
{
	int n(0), m(0);
	vector<struct user> users;
	cin >> n >> m;
	string* user = new string[n + 1];
	while (cin >> user[0])
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> user[i + 1];
		}
		users.push_back(process(user, n, m));
	}
	sort(users.begin(), users.end(), cmp);
	vector<struct user>::iterator iter = users.begin();
	while (iter < users.end())
	{
		printf("%-10s %2d %4d",iter->name.c_str(),iter->Score,iter->Penalty);
		iter++;
		if (iter != users.end())
			printf("\n");
	}
	return 0;
}