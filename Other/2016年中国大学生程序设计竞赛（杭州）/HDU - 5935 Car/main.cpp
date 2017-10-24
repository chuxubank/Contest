//
// main.cpp
// HDU - 5935 Car
//
// Created by chuxu on 2017/10/14 下午 4:35:06.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 7;
typedef long long ll;
ll a[maxn];
double b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t, n, c=0;
	cin >> t;
	while (t--)
	{
		ll ans = 0;
		cin >> n;
		a[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			b[i] = (a[i] - a[i - 1])*1.0;
		}
		double speed = b[n];
		int time = 0;
		for (int i = n; i >= 1; i--)
		{
			time = b[i] / speed;
			ans += time;
			if (b[i] / time != speed)
			{
				ans++;
				speed=b[i]/(time+1);
			}
		}
		cout << "Case #" << ++c << ": "<<ans << endl;
	}
	return 0;
}