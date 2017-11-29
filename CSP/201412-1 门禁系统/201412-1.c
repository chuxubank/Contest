#include <stdio.h>
int main()
{
	int i,n,count,j;
	static a[1001],b[1001];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (a[i] == a[j])
				b[i]++;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}