#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <map>  
#include <algorithm>  
using namespace std;
typedef long long LL;
const LL LINF = 1e18 + 7;
const int maxn = 2005;
const int maxx = 1e5 + 100;
inline LL Scan()
{
	LL Res = 0, ch, Flag = 0;
	if ((ch = getchar()) == '-')Flag = 1;
	else if (ch >= '0' && ch <= '9')Res = ch - '0';
	while ((ch = getchar()) >= '0'&&ch <= '9')Res = Res * 10 + ch - '0';
	return Flag ? -Res : Res;
}

LL dp[maxn][14];  
LL a[maxx], b[maxx], k[maxn], p[maxn];

int main()
{ 
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 1; i <= n; i++)
		{
			a[i] = Scan(); b[i] = Scan();
		}
		for (int i = 1; i <= m; i++)
		{
			k[i] = Scan(); p[i] = Scan();
		}
		for (int i = 0; i<maxn; i++)
			for (int j = 0; j <= 10; j++)
				dp[i][j] = LINF;
		for (int i = 0; i <= 10; i++)
		{
			dp[0][i] = 0;
			for (int j = 1; j <= m; j++)
			{
				LL t = p[j] - i;  
				if (t <= 0) continue;
				for (int p = t; p <= 2003; p++)
				{
					dp[p][i] = min(dp[p - t][i] + k[j], dp[p][i]);
				}
			}
			for (int j = 2002; j >= 0; j--)   
			{
				dp[j][i] = min(dp[j][i], dp[j + 1][i]);
			}
		}
		LL ans = 0;
		for (int i = 1; i <= n; i++)
			ans += dp[a[i]][b[i]];
		if (ans >= LINF)
			puts("-1");
		else cout << ans << endl;
	}
}