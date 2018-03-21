#include <bits/stdc++.h>
using namespace std;

int main()
{
	int len;
	char c;
	string s;
	cin >> len >> c;
	cin.get();
	getline(cin, s);
	int s_len = s.length();
	if(s_len < len)
		s.insert(0, len - s_len, c);
	else
		s.erase(0, s_len - len);
	cout << s;
	return 0;
}