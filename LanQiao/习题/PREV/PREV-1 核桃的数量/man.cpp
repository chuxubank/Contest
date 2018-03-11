#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int lcm1 = a * b / gcd(a, b);
	cout << lcm1 * c / gcd(lcm1, c) << endl;
	return 0;
}

//GCD模版