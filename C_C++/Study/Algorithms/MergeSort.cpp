#include <iostream>
using namespace std;

void mergeSort(int head, int tail, int* arr)
{
	if (tail == head)
		return;
	int middle = (tail + head) / 2;
	mergeSort(head, middle, arr);
	mergeSort(middle + 1, tail, arr);
	int length = tail - head + 1;
	int* temp = new int[length];
	int* ptemp(temp);
	int *parr1(&arr[head]), *parr2(&arr[middle + 1]);
	while (parr1 <= &arr[middle] && parr2 <= &arr[tail])
	{
		if (*parr1 <= *parr2)
			*ptemp++ = *parr1++;
		else
			*ptemp++ = *parr2++;
	}
	while (parr1 <= &arr[middle])
		*ptemp++ = *parr1++;
	while (parr2 <= &arr[tail])
		*ptemp++ = *parr2++;
	for (int i = 0; i < length; i++)
		arr[head + i] = temp[i];
	delete[] temp;
}

int main()
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	mergeSort(0, n - 1, arr);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	delete[] arr;
	return 0;
}
