#include <bits/stdc++.h>
using namespace std;

int main()
{
	string input;
	cin >> input;
	map<char, int> count;
	for(auto c : input)
	{
		count[c]++;
	}
	for(auto it : count)
	{
		cout << it.first << ":" << it.second << endl;
	}
	return 0;
}