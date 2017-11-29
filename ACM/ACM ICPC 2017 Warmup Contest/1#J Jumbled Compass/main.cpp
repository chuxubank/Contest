//
// main.cpp
// J Jumbled Compass
//
// Created by chuxu on 2017/10/3 下午 1:29:40.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int a, b, ans = 0;
	cin >> a >> b;
	if (b - a >= 0 && b - a <= 180 || b - a <= 0 && b - a >= -180)
		ans = b - a;
	else if (b - a>0 && b - a>180)
		ans = b - a - 360;
	else if (b - a<0 && b - a<-180)
		ans = b - a + 360;
	cout << ans << endl;
	return 0;
}