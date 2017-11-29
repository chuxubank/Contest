#include <stdio.h>
int main()
{
	int i,j,a[1001],n,flag=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] == a[j] + 1 || a[i] == a[j] - 1)
				flag++;
		}
	}
	printf("%d", flag);
	return 0;
}