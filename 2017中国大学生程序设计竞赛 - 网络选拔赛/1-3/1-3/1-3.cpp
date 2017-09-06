#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

const int MAX = 3000;

bool G[MAX][MAX];
int deg[MAX];

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(G, 0, sizeof(G));
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				int temp;
				scanf("%d", &temp);
				if (temp == 0)
					G[i][j] = false;
				else if (temp == 1)
				{
					G[i][j] = true;
					G[j][i] = true;
					deg[i]++;
					deg[j]++;
				}
			}
		}
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = j + 1; k <= n; k++)
				{
					if (G[i][j] == true && G[i][k] == true && G[j][k] == true)
					{
						flag = true;
						break;
					}
					else if (G[i][j] == false && G[i][k] == false && G[j][k] == false)
					{
						flag = true;
						break;
					}
				}
				if (flag == true)
					break;
			}
			if (flag == true)
				break;
		}
		if (flag == true)
			printf("Bad Team!\n");
		else
			printf("Great Team!\n");
	}
	return 0;
}