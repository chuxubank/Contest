//
// main.cpp
// POJ - 2159 Ancient Cipher
//
// Created by chuxu on 2017/10/5 上午 9:06:36.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e9 + 7;
int main()
{
	string a,b;
	int a1[27],b1[27];
	bool flag=1;
	memset(a1, 0, sizeof(a1));
	memset(b1, 0, sizeof(b1));
	cin >> a;
	cin >> b;
	for (int i = 0; i < a.size(); i++)
		a1[a[i] - 'A']++;
	for (int i = 0; i < b.size(); i++)
		b1[b[i] - 'A']++;
	sort(a1, a1 + 26);
	sort(b1, b1 + 26);
	for (int i = 0; i < 26; i++)
	{
		if (a1[i] != b1[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}