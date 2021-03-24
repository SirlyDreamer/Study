#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int InputNumber(char ch)
{
	int num = -1;
	while (num <= 1)
	{
		printf("Please input the number %c(>1):", ch);
		scanf("%d", &num);
		if (num > 1)
			return (unsigned int) num;
		else
			printf("The input must be an integer larger than 1!\n");
	}
    return 0;
}

int IsPrime(unsigned int n)
{
	int res = 0;
	if (n == 2)
		return 1;
	int maxi = sqrt(n);
	for (int i = 2; i <= maxi; ++i)
	{
		res = (n % i == 0);
		if (res)
			return 0;
	}
	return 1;
}

int PrimeSum(unsigned int m, unsigned int n)
{
	int sum = 0;
	for (int i = m; i <= n; ++i)
		if (IsPrime(i))
		{
			printf("%d\n", i);
			sum += i;
		}
	return sum;
}

int main()
{
	int m = 0, n = 0, sum = 0, i = 0;
	do
	{
		m = InputNumber('m');
		n = InputNumber('n');
	} while (m > n && printf("n must be not smaller than m! Input again!\n"));   //保证m<=n
	sum = PrimeSum(m, n);
	printf("sum of prime numbers:%d", sum);
	return 0;
}
