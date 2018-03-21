#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int visit[maxn];

int main()
{
	int n, m, k, id;
	while(~scanf("%d", &n))
	{
		memset(visit, 0, sizeof(visit));
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			for(int j = 0; j < k; j++)
			{
				scanf("%d", &id);
				if(k == 1)
					break;      //只有自己的朋友圈排出
				visit[id] = 1;
			}
		}
		scanf("%d", &m);
		int searId, flag = 0;
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &searId);
			if(!visit[searId])
			{
				if(++flag > 1)
					printf(" ");
				printf("%05d", searId);
				visit[searId] = 1;
			}
		}
		if(flag == 0)
			printf("No one is handsome");
		printf("\n");
	}
	return 0;
}
