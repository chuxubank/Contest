#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,b[1000],i1,i2;
	int a[500][500];
	int n,m;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	m = n * 2 - 1;//对角线数
	//统计每层个数
	for (i = 1; i <= (m + 1) / 2; i++)
		b[i] = i;
	for (i = (m + 1) / 2; i <= m; i++)
		b[i] = m - i + 1;
	i = 0; j = 0;
	//处理上三角
	for (i1 = 1; i1 <= (m + 1) / 2; i1++)
		for (i2 = 1; i2 <= b[i1]; i2++)
		{
			i = i1 - j - 1;
			j = i1 - i - 1;
			printf("%d ", a[i][j]);
			if (i1 % 2 == 0 && j != 0)
				j--;
			if (i1 % 2 == 0 && j == 0)
				i++;
			if (i1 % 2 != 0)
				j++;
		}
	//调整为副对角线最后一个元素
	i1--;
	if (i1 % 2 == 0)
		i--;
	else
		j--;
	//处理下三角
	for (i1 = (m + 1) / 2 + 1; i1 <= m; i1++)
	{
		if ((i1 - 1) % 2 == 0)
			j++;
		else
			i++;
		for (i2 = 1; i2 <= b[i1]; i2++)
		{
			printf("%d ", a[i][j]);
			if (i1 % 2 == 0 && i<n - 1)
			{
				i++;
				j = i1 - i - 1;
			}
			if (i1 % 2 != 0 && j<n - 1)
			{
				j++;
				i = i1 - j - 1;
			}
		}
	}
	return 0;
}