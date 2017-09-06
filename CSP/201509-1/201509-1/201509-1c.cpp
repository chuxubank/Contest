#include<stdio.h>
int main()
{
	int i, n,a[1001];
	int count;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	count = 0;
	for (i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
			count++;
	}
	printf("%d", count+1);
	return 0;
}