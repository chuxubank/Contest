#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	struct windows
	{
		int x1;
		int x2;
		int y1;
		int y2;
		int numb;
	}w[11];
	struct mouse
	{
		int x;
		int y;
	}mou[11];
	int i,j,k,n,m,flag=0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = n,j=1; i >= 1; i--,j++)
	{
		scanf("%d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
		w[i].numb = j;
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &mou[i].x, &mou[i].y);
	}
	for (i = 1; i <= m; i++)
	{
		flag = 0;
		for (j = 1; j <= n; j++)
		{
			if (mou[i].x >= w[j].x1 && mou[i].x <= w[j].x2 && mou[i].y <= w[j].y2 && mou[i].y >= w[j].y1)
			{
				printf("%d\n", w[j].numb);
				w[0] = w[j];
				for (k = j; k > 0; k--)
				{
					w[k] = w[k - 1];
				}
				flag = 1;
				break;
			}
		}
		if (flag==0)
		{
			printf("IGNORED\n");
		}
	}
	return 0;
	getchar();
}