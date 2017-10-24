//
// main.cpp
// Round 440 - B. Maximum of Maximums of Minimums
//
// Created by chuxu on 2017/10/15 下午 4:51:03.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 7;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	vector<int> a(maxn);
	ll maxa = -1e9 - 7, mina = 1e9 + 7,ans;	//注意负数时要取-号 要么直接用INI_MIN
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > maxa)
			maxa = a[i];
		if (a[i] < mina)
			mina = a[i];
	}
	if (k == 1)
		ans = mina;
	else if (k == 2)
		ans = max(a[0], a[n - 1]);
	else
		ans = maxa;
	cout << ans << endl;
	return 0;
}