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
		string in;
		cin >> in;
		int len = 2 * n - 2;
		string s;
		for (int i = 0; i < len; i++)
			s.append(1, in[i] == 'S' ? 'E' : 'S');
		printf("Case #%d: %s\n", c, s.c_str());
	}
	return 0;
}