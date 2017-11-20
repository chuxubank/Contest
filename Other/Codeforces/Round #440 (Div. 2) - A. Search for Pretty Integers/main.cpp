//
// main.cpp
// Round 440 - A. Search for Pretty Integers
//
// Created by chuxu on 2017/10/15 下午 4:10:39.
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
	int n, m;
	vector<int> a(10,-1), b(10,-1);
	cin >> n >> m;
	int ans = 0, mina = 10, minb = 10, minn=10;
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (mina > a[i])
			mina = a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		if (minb > b[i])
			minb = b[i];
	}
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j])
			{
				if (minn > a[i])
					minn = a[i];
				flag = true;
			}
		}
	}
	if (mina > minb)
		swap(mina, minb);
	if (flag)
		cout << minn << endl;
	else
		cout << mina << minb << endl;
	return 0;
}