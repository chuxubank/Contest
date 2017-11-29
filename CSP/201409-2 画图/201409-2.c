#include <stdio.h>
int main()
{
	struct dot
	{
		int x;
		int y;
	}dot1,dot2;
	int i,j,k ,n,count=0;
	static int a[100][100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &dot1.x, &dot1.y, &dot2.x, &dot2.y);
		for (j = dot1.x; j < dot2.x; j++)
		{
			for (k = dot1.y; k < dot2.y; k++)
			{
				a[j][k] = 1;
			}
		}
	}
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			if (a[i][j] == 1)
			{
				count++;
			}
		}
	}
	printf("%d", count);
}