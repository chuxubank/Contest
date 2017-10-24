//
// main.cpp
// Round 440 - C. Maximum splitting
//
// Created by chuxu on 2017/10/15 下午 5:07:54.
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
int a[17] = { -1,-1,-1,-1,1,-1,1,-1,2,1,2,-1,3,2,3,2,4 };
//vector<int> a(b,b+17);
int main()
{
	ios::sync_with_stdio(false);
	//for (int i = 0; i <= 16; i++)
	//{
	//	cout << i << " " << a[i] << endl;
	//}
	int q;
	cin >> q;
	while (q--)
	{
		int in,ans=0;
		cin >> in;
		while (in > 16)
		{
			in -= 4;
			ans += 1;
		}
		ans += a[in];
		cout << ans << endl;
	}
	return 0;
}