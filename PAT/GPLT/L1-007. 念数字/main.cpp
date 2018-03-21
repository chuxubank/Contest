#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<char, string> m;
	m['-'] = "fu";
	m['0'] = "ling";
	m['1'] = "yi";
	m['2'] = "er";
	m['3'] = "san";
	m['4'] = "si";
	m['5'] = "wu";
	m['6'] = "liu";
	m['7'] = "qi";
	m['8'] = "ba";
	m['9'] = "jiu";
	string input;
	cin >> input;
	for(int i = 0; i < input.length() - 1; i++)
		cout << m[input[i]] << " ";
	cout << m[input[input.length() - 1]];
	return 0;
}