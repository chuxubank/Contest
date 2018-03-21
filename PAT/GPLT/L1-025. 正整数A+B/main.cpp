#include <bits/stdc++.h>
using namespace std;

int main()
{
	stringstream ss;
	string a, b;
	cin >> a;
	cin.get();
	getline(cin, b);
	int a_int, b_int;
	ss << a;
	ss >> a_int;
	if(a != to_string(a_int) || a_int < 1 || a_int > 1000)
		a = "?";
	ss.str("");
	ss.clear();
	ss << b;
	ss >> b_int;
	b_int = abs(b_int);
	if(b != to_string(b_int) || b_int < 1 || b_int > 1000)
		b = "?";
	string ans;
	int ans_int;
	if(a != "?" && b != "?")
	{
		ans_int = a_int + b_int;
		ans = to_string(ans_int);
	}
	else
		ans = "?";
	cout << a
	     << " + "
	     << b
	     << " = "
	     << ans;
	return 0;
}