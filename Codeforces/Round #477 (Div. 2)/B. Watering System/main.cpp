#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int s[100005];
bool bs[100005];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	int sumsize = 0;
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		sumsize += s[i];
	}
	memset(bs, 0, sizeof(bs));
	sort(s + 1, s + n, cmp);
	// for(int i = 0; i < n; i++)
	// {
	//  printf("%d ", s[i]);
	// }
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		double now = 1.0 * a * s[0] / sumsize;
		if(now >= b)
			break;
		else
		{
			bs[i] = true;
			sumsize -= s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}