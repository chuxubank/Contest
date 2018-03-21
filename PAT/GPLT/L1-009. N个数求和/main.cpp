#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
	return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
	ll t, a[101], b[101], s1 = 0, s2 = 0;
	scanf("%lld", &t);
	for(int i = 0; i < t; i++)
		scanf("%lld/%lld", &a[i], &b[i]);
	s2 = b[0];
	for(int i = 1; i < t; i++)
		s2 = s2 / gcd(s2, b[i]) * b[i];
	for(int i = 0; i < t; i++)
		s1 += s2 / b[i] * a[i];
	ll n = s1 / s2, m = abs(s1 % s2);
	if(m == 0)
		printf("%lld\n", n);
	else
	{
		if(n != 0)
			printf("%lld ", n);
		if(s1 < 0 && n == 0)
			printf("-");
		printf("%lld/%lld\n", m / gcd(s2, m), s2 / gcd(s2, m));
	}
	return 0;
}