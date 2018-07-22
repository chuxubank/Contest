#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, k;
	map<int, int> pairs;
	cin >> n >> m >> k;
	int a[n], b[m];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for(int i = 0; i < k; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		pairs[t1] = t2;
		pairs[t2] = t1;
	}
	if(n < m)
	{
		cout << "No" << endl;
		return 0;
	}
	int i = 0;
	for(; i < m; i++)
	{
		if(pairs[a[i]] != b[i] && pairs[b[i]] != a[i])
		{
			if(a[i] != b[i])
			{
				break;
			}
		}
	}
	if(i == m)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}