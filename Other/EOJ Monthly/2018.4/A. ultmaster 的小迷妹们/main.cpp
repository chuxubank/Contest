#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	if(n % (gcd(x, y)) != 0)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}