#include <stdio.h>
using namespace std;

int main()
{
	int a[101][101];
	int b[101][101];
	int m, n;
	int x, y;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	scanf("%d%d", &x, &y);
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			scanf("%d", &b[i][j]);

	if(n != x)
	{
		printf("Error: %d != %d\n", n, x);
	}
	else
	{
		printf("%d %d\n", m, y);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < y; j++)
			{
				int sum = 0;
				for(int k = 0; k < n; k++)
					sum += a[i][k] * b[k][j];
				if(j < y - 1)
					printf("%d ", sum);
				else
					printf("%d\n", sum);
			}
		}
	}
	return 0;
}
