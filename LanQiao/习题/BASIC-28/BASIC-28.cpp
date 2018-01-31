#include <iostream>
#include <algorithm>
using namespace std;
int huffmanpay(int a[101], int start, int n);
int main()
{
	int i, j, n;
	int a[101];
	scanf("%d", &n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d",huffmanpay(a, 0, n));
	return 0;
}
int huffmanpay(int a[101], int start, int n)
{
	int temp = 0;
	static int sum = 0;
	if (start + 1 == n)
	{
		return sum;
	}
	else
	{
		sort(a + start, a + n);
		temp = a[start] + a[start + 1];
		a[start+1] = temp;
		sum += temp;
		huffmanpay(a, start + 1, n);
	}
}