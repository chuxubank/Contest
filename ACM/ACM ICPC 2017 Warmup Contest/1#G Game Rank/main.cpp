//
// main.cpp
// G Game Rank
//
// Created by chuxu on 2017/10/3 下午 1:32:05.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int maxn = 1e9 + 7;
int getrankstar(int rank)
{
	if (rank <= 25 && rank >= 21)
		return 2;
	if (rank <= 20 && rank >= 16)
		return 3;
	if (rank <= 15 && rank >= 11)
		return 4;
	if (rank <= 10 && rank >= 1)
		return 5;
	else
		return 0;
}
int main() {
	int rank = 25;
	int stars = 0;
	int consecutive = 0;
	string s;
	cin >> s;
	for (char c : s) 
	{
		if (rank == 0) 
			break;
		if (c == 'W')
		{
			consecutive++;
			stars++;
			if (rank >= 6 && consecutive >= 3)
				stars++;
			if (stars>getrankstar(rank))
				stars -= getrankstar(rank--);
		}
		else 
		{
			consecutive = 0;
			if (stars == 0 && rank<20)
				stars = getrankstar(++rank);
			if (rank <= 20 && stars>0)
				stars--;
		}
	}
	if(rank) 
		cout << rank << endl;
	else 
		cout << "Legend" << endl;
}