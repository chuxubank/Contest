#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b, ans;
	getline(cin, a);
	getline(cin, b);
	for(char c : a)
	{
		if(find(b.begin(), b.end(), c) == b.end())
		{
			ans += c;
		}
	}
	cout << ans;
	return 0;
}

//注意不能一边遍历一边erase否则会越界