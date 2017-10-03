//
// main.cpp
// LeetCode - 682 Baseball Game
//
// Created by chuxu on 2017/9/24 上午 9:51:49.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 1e9 + 7;

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> v;
		for (int i = 0; i<ops.size(); i++)
		{
			if (ops[i] == "+")
				v.push_back(v[v.size() - 1] + v[v.size() - 2]);
			else if (ops[i] == "D")
				v.push_back(2 * v[v.size() - 1]);
			else if (ops[i] == "C")
				v.pop_back();
			else
				v.push_back(atoi(ops[i].c_str()));
		}
		int sum = 0;
		for (int i : v)
			sum += i;
		return sum;
	}
};

int main()
{
	return 0;
}