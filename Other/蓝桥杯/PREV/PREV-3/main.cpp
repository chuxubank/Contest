//
// main.cpp
// PREV-3
//
// Created by chuxu on 2017/10/12 下午 9:42:32.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;
const int maxn = 1e9 + 7;
int countn,input = 0;
vector<int> a(10,-1);

int ToNum(int s, int n)
{
	int i, temp = 0;
	for (i = 0; i<n; i++)
		temp = temp * 10 + a[s + i];
	return temp;
}

bool find(int t)
{
	int i;

	for (i = 0; i<9; i++)
	{
		if (a[i] == t)
		{
			return true;
		}
	}
	return false;
}

void arrange()
{
	int i, j;
	int num1, num2, num3;
	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7 - i + 1; j++)
		{
			if (j < 9 - i - j)
				continue;
			else
			{
				num1 = ToNum(0, i);
				num2 = ToNum(i, j);
				num3 = ToNum(i + j, 9 - i - j);
				if (((num2 % num3) == 0) && (num1 + num2 / num3) == input)
					countn++;
				else
					continue;
			}
		}
	}
}

void dfs(int pos)
{
	if (pos == 9)
	{
		arrange();
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (!find(i))
		{
			a[pos] = i;
			dfs(pos + 1);
			a[pos] = -1;
		}
	}
}

int main()
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	cin >> input;
	dfs(0);
	cout << countn << endl;
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;

	return 0;
}