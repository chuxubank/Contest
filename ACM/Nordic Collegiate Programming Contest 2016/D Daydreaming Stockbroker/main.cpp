//
// main.cpp
// D Daydreaming Stockbroker
//
// Created by chuxu on 2017/10/3 下午 3:19:01.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
	ll money = 100, days, prev = 1 << 30, cur;
	cin >> days;
	for (int i = 0; i < days; ++i, prev = cur)
	{
		cin >> cur;
		if (cur > prev)
			money += min(money / prev, 100000LL)*(cur - prev);
	}
	cout << money << endl;
	return 0;
}