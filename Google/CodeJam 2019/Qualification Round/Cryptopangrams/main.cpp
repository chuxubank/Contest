#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++)
	{
		int n, l;
		cin >> n >> l;
		vector<int> data(l);
		vector<int> decode(l + 1);
		set<int> s;
		vector<int> cpy;
		map<int, char> m;
		for (int i = 0; i < l; i++)
			cin >> data[i];
		for (int i = 1; i < l; i++)
			decode[i] = gcd(data[i - 1], data[i]);
		decode[0] = data[0] / decode[1];
		decode[l] = data[l - 1] / decode[l - 1];
		for (int i = 0; i < l + 1; i++)
			s.insert(decode[i]);
		auto iter = s.begin();
		while (iter != s.end())
		{
			cpy.push_back(*iter);
			iter++;
		}
		sort(cpy.begin(), cpy.end());
		for (int i = 0; i < 26; i++)
			m[cpy[i]] = 'A' + i;
		printf("Case #%d: ", c);
		for (int i = 0; i < l + 1; i++)
			cout << m[decode[i]];
		cout << endl;
	}
	return 0;
}