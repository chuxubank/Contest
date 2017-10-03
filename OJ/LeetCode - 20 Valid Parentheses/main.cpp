//
// main.cpp
// LeetCode - 20 Valid Parentheses
//
// Created by chuxu on 2017/9/23 上午 11:01:50.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1e9 + 7;
class Solution {
public:
	bool isValid(string s) {
		stack<char> paren;
		for (char& c : s)
		{
			switch (c)
			{
			case '(':
				paren.push(')');
				break;
			case '{':
				paren.push('}');
				break;
			case '[':
				paren.push(']');
				break;
			default:
				if (paren.empty() || paren.top() != c)
					return false;
				else
					paren.pop();
				break;
			}
		}
		return paren.empty();
	}
};

int main()
{
	string a;
	cin >> a;
	Solution s;
	cout << s.isValid(a) << endl;
}