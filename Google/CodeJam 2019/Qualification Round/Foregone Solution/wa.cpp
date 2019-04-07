#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++)
	{
		int n;
		cin >> n;
		int a = 0;
		int tmp = n, i = 1;
		while (tmp)
		{
			if (tmp % 10 == 4)
				a += 1 * i;
			tmp /= 10;
			i *= 10;
		}
		printf("Case #%d: %d %d\n", c, a, n - a);
	}
	return 0;
}

// n could be greater than 1e100
// int is within 1e9
// long long is within 1e18
// so use Java or Python or string