//
// main.cpp
// B Coin
//
// Created by chuxu on 2017/9/16 下午 1:49:05.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;

long long a;
long long b;
const int mod = 1e9 + 7;

long long p, q, k;

void extra_gcd(LL a, LL b, LL &x, LL &y, LL &d)
{
	if (b == 0)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		extra_gcd(b, a%b, y, x, d);
		y -= (a / b) * x;
	}
}

void solve();
long long quick_pow(long long n, long long k)
{
	n = n%mod;
	long long ans = 1;
	while (k>0)
	{
		if (k & 1)
			ans = ans*n%mod;
		n = n*n%mod;
		k >>= 1;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		LL x,y,d;
		scanf("%lld %lld %lld", &p, &q, &k);
		solve();
		extra_gcd(b, mod, x, y, d);
		x = (x + p) % p;
		printf("%lld\n", (a * x) % mod);
	}
	return 0;
}

void solve()
{
	a = (((quick_pow(2, k - 1) - 1)*quick_pow(q, k)) % mod + quick_pow(p - q, k)) % mod;
	b = quick_pow(p, k);
}