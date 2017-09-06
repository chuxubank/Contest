#include<cstdio>
int n, m, k, ca;
int a[100002];
int main()
{
	scanf("%d", &ca);
	for (int i = 0; i < ca; i++)
	{
		scanf("%d", &n);
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			a[i] %= 2;
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1)
				count++;
		}
		if (count * 2 >= n)
			printf("2 1\n");
		else
			printf("2 0\n");
	}
	
	return 0;
}