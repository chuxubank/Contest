#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++)
	{
		string s;
		cin >> s;
		string a, b;
		int n = (int)s.length();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '4')
			{
				a += '3';
				b += '1';
			}
			else
			{
				a += s[i];
				if (!b.empty())
					b += '0';
			}
		}
		if (b.empty())
			b += '0';
		printf("Case #%d: %s %s\n", c, a.c_str(), b.c_str());
	}
	return 0;
}