#include <bits/stdc++.h>
using namespace std;

void p(int max, int cur, char c)
{
	for(int i = 0; i < max - cur; i++)
	{
		if(i < cur)
			cout << " ";
		else
			cout << c;
	}
	cout << endl;
	if(max - 2 * (cur + 1) <= 0)
		return;
	p(max, cur + 1, c);
	for(int i = 0; i < max - cur; i++)
	{
		if(i < cur)
			cout << " ";
		else
			cout << c;
	}
	cout << endl;
}

int main()
{
	int n, cur = 1;
	char c;
	cin >> n >> c;
	int a = n - 1;
	while(a >= 2 * (cur + 2))
	{
		cur += 2;
		a -= 2 * cur;
	}
	p(cur, 0, c);
	cout << a << endl;
	return 0;
}