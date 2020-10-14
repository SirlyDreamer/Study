#include <stdio.h>
int main()
{
	int m, n, k = 0, p = 1, d;
	printf("input m, n \n");
	scanf("%d %d",&m,&n);
	if (m < n)						/* 交换m和n */
	{
		m ^= n;
        n ^= m;
        m ^= n;
    }
	while (m &  == 0 && n % 2 == 0)			/* m和n均为偶数 */
	{
		m = m >> 1;								/* 用2约简m和n */
		n = n >> 1;
		k++;
	}
	p = p << k;			/* 求p=2^k */
	while (m - n != n)
	{
        d = m - n;
		if (d > n)
            m = d;
		else
		{
			m = n;
			n = d;
		}
	}
    d = m-n;
	d *= p;
	printf("the greatest common divisor : %d", d);
	return 0;
}
