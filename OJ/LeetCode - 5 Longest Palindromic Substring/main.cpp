//
// main.cpp
// LeetCode - 5 Longest Palindromic Substring
//
// Created by chuxu on 2017/10/3 下午 9:33:57.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e9 + 7;

string longestPalindrome(string s) {
	string t = "$#";    //初始化字符串（添加特殊字符） $防止越界
	for (int i = 0; i < s.size(); ++i) {
		t += s[i];
		t += '#';
	}
	vector<int> p(t.size(),0);//p数组存放以字符t[i]为中心的最长回文字串的最右字符到t[i]的长度，p[i]-1即为s串中的最长回文串的长度
	int id = 0, mx = 0, resId, resMx = 0;//mx：已知的最长回文串的右边界，id：已知最长回文串的中心
	for (int i = 1; i < t.size(); ++i) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;//未探寻的i的p[i]赋为1，否则取（i与id对称位置处的p[j]）和（i到右边界）的较小值
		while (t[i + p[i]] == t[i - p[i]])//继续探寻直到不为回文。
			++p[i];
		if (mx < i + p[i]) {//刷新右边界和中心
			mx = i + p[i];
			id = i;
		}
		if (resMx < p[i]) {//刷新答案
			resMx = p[i];
			resId = i;
		}
	}
	return s.substr((resId - resMx) / 2, resMx - 1);//t的长度恰为s的两倍（s长度为偶数）/2s+1（s长度为奇数）
}

int main()
{
	string s;
	cin >> s;
	cout << longestPalindrome(s);
	return 0;
}