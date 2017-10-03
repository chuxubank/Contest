#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, m,ans;
int ca;
int main()
{
	cin >> ca;
	while (ca--)
	{
		cin >> n >> m;
		if ((n*n - n)/2 <= m)
		{
			ans = n*n - n;
		}
		else if (m >= n - 1)
		{
			ans = n*n - n + 2*((n*n - n) / 2 - m);
		}
		else
		{
			ans = 2 * n*n - 4 * n + 2;
			ans += (4 * (n*n - 3 * n + 3) - (n - 2 - m)*(2 * (n - 2)))*(n - 1 - m) / 2;
		}
		cout << ans << endl;
	}
}