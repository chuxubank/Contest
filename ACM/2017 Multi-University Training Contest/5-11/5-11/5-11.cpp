#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
bool comp(int a, int b)
{
	return a>b;
}

int main()
{
	int ca;
	cin >> ca;
	while (ca--)
	{
		int ans = 1;
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, comp);
		for (int i = 0; i<n - 1; i++)
		{
			if (a[i] - k <= a[i + 1])
				ans++;
			else
				break;
		}
		cout << ans << endl;
	}
	return 0;
}