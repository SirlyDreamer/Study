#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m, n(0), x1(0), x2(0), i;
	cin >> m;
	n = m;
	bool a(true);
	do
	{
		for (i = 2; i <= sqrt(n); i++)
			if (n % i == 0)
				a = false;
		if (a == true)
		{
			x1 = n;
			n = x1 - 2;
			for (i = 2; i <= sqrt(n); i++)
				if (n % i == 0)
					a = false;
			if (a == true)
			{
				x2 = n;
				cout << x2 << " " << x1;
			}
			else
			{
				x2 = 0;
				n = n + 2;
			}
		}
		n--;
		a = true;
	} while (x2 == 0);
	return 0;
}