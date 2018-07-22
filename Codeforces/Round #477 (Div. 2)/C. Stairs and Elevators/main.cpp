#include <bits/stdc++.h>
using namespace std;

int n, m, csta, cele, v;
vector<int> psta(100005), pele(100005);

int main()
{
	scanf("%d %d %d %d %d", &n, &m, &csta, &cele, &v);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &psta[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &pele[i]);
	}
	int p;
	scanf("%d", &p);
	for(int i = 0; i < p; i++)
	{
		int x1, y1, x2, y2;
		int ans = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(y1 < min(psta[0], pele[0]) && y2 > max(psta[csta - 1], pele[cele - 1]))
		{
			ans = abs(y1 - y2) + abs(x1 - x2) / v + ((abs(x1 - x2) % v > 0) ? 1 : 0);
		}
		if(y2 < min(psta[0], pele[0]) && y1 > max(psta[csta - 1], pele[cele - 1]))
		{
			ans = abs(y1 - y2) + abs(x1 - x2) / v + ((abs(x1 - x2) % v > 0) ? 1 : 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}