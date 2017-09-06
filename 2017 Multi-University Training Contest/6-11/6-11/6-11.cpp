#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int t, n, maxn,a[10],b[10],ans;
int main()
{
	cin >> t;
	while (t--)
	{
		maxn = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int flag = 0;
			ans = 0;
			for (int i = 1; i <= 7; i++)
			{
				cin >> a[i];
			}
			b[7] = a[7];
			b[6] = a[6] - a[7];
			b[5] = a[5] - a[7];
			b[4] = a[4] - a[7];
			b[3] = a[3] - b[5] - b[6] - a[7];
			b[2] = a[2] - b[4] - b[5] - a[7];
			b[1] = a[1] - b[4] - b[6] - a[7];
			for (int i = 1; i <= 7; i++)
			{
				if (b[i] < 0)
					flag = 1;
			}
			if (flag == 0)
			{
				for (int i = 1; i <= 7; i++)
				{
					ans += b[i];
				}
			}
			if (ans > maxn)
				maxn = ans;
		}
		cout << maxn << endl;
	}
	return 0;
}