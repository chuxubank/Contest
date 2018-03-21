#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t = 1, sum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		t *= i;
		sum += t;
	}
	cout << sum;
	return 0;
}