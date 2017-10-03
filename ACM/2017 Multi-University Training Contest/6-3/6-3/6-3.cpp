#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct s {
	long long data;
	int index;
}A[100010];

bool comp(s s1, s s2)
{
	return s1.data > s2.data;
}

int main()
{
	int n, t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &A[i].data);
			A[i].index = i;
		}
		sort(A + 1, A + n + 1, comp);
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (A[j].index % i != 0)
				{
					printf("%lld", A[j].data);
					if (i == n)
						printf("\n");
					else
						printf(" ");
					break;
				}
			}
		}
	}
	return 0;
}