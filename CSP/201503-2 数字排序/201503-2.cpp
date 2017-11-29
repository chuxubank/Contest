#include<stdio.h>
int main()
{
	int temp, i, j, n;
	static a[1001];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		a[temp]++;
	}
	for (i = 1000; i > 0; i--)
	{
		for (j = 0; j < 1001; j++)
		{
			if (a[j] == i)
				printf("%d %d\n", j, a[j]);
		}
	}
}
