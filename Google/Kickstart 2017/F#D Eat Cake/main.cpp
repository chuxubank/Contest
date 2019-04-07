//
// main.cpp
// D Eat Cake
//
// Created by chuxu on 2017/9/24 下午 7:18:26.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e9 + 7;
int numSquares(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	static vector<int> cntPerfectSquares({ 0 });
	while (cntPerfectSquares.size() <= n)
	{
		int m = cntPerfectSquares.size();
		int cntSquares = INT_MAX;
		for (int i = 1; i*i <= m; i++)
		{
			cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
		}
		cntPerfectSquares.push_back(cntSquares);
	}
	return cntPerfectSquares[n];
}

int main()
{
	ifstream infile;
	infile.open("D-small-attempt1.in");
	ofstream outfile;
	outfile.open("D-small-attempt1.out");
	int t, i = 1, n;
	infile >> t;
	while (i<=t)
	{
		infile >> n;
		outfile << "Case #" << i++ << ": " << numSquares(n) << endl;
	}
	return 0;
}