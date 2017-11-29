#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;
ll dp[2005][11], a[100010], b[100010], k[2005], p[2005];
int n, m;
int main()
{
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (int i = 0; i<n; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
		}
		for (int i = 0; i<m; i++)
		{
			scanf("%d %d", &k[i], &p[i]);
		}
		for (int i = 0; i<2005; i++)
			for (int j = 0; j <= 10; j++)
				dp[i][j] = INF;
		for (int i = 0; i<=10; i++)
		{
			dp[0][i] = 0;
			for (int j = 0; j<m; j++)
			{
				ll pb = p[j] - i;
				if (pb <= 0)
					continue;
				for (int l = pb; l<2004; l++)
				{
					dp[l][i] = min(dp[l - pb][i] + k[j], dp[l][i]);
				}
			}
			for (int j = 2002; j >= 0; j--)   
			{
				dp[j][i] = min(dp[j][i], dp[j + 1][i]);
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans += dp[a[i]][b[i]];
		if (ans >= INF)
			printf("-1");
		else 
			printf("%d",ans);
	}
}