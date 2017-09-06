#include <stdio.h>
#include <algorithm>
int kbignumque(int n, int a[1002], int l, int r, int k);
int main()
{
	int a[1002], n, m, i, j, l, r, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", kbignumque(n, a, l, r, k));
	}
	return 0;
}
int kbignumque(int n, int a[1002], int l, int r, int k)
{
	int i, j;
	int b[1002];
	for (i = l, j = 0; i <= r; i++, j++)
	{
		b[j] = a[i];
	}
	std::sort(b, b + r - l + 1);
	return b[r - l + 1 - k];
}