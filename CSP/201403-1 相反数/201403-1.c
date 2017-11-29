#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, *a;
	int i, j, count=0;
	scanf("%d", &n);
	a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		for (j = 0; j < i; j++)
		{
			if (a[i] == -a[j])
			{
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}
