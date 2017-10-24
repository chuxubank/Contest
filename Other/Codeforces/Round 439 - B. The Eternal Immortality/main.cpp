//
// main.cpp
// Round 439 - B. The Eternal Immortality
//
// Created by chuxu on 2017/10/15 下午 8:26:04.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e9 + 7;
int main()
{
	ios::sync_with_stdio(false);
	ll a, b, d, ans=1;
	cin >> a >> b;
	d = b - a;
	if (d >= 10)
		ans = 0;
	else if (d == 0)
		ans = 1;
	else
	{
		int c = b%10;
		for (; b > a; b--,c--)
			ans *= c;
		ans %= 10;
	}
	cout << ans << endl;
	return 0;
}