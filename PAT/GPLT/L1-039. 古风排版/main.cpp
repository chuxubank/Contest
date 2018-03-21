#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin.get();
	getline(cin, s);
	if(s.length() % n != 0)
	{
		s.insert(s.length(), n - (s.length() % n), ' ');
	}
	vector<string> ans(n);
	for(int i = 0; i < s.length(); i++)
	{
		ans[i % n] += s[i];
	}
	for(int i = 0; i < n; i++)
	{
		reverse(ans[i].begin(), ans[i].end());
		cout << ans[i] << endl;
	}
	return 0;
}