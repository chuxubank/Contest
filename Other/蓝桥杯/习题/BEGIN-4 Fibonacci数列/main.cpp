#include <bits/stdc++.h>
using namespace std;
int f[1000001];

int main()
{
	f[1] = f[2] = 1;
	int in;
	cin >> in;
	for(int i = 3; i <= in; i++)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 10007;
	}
	cout << f[in];
	return 0;
}