//
// main.cpp
// POJ - 2965 The Pilots Brothers' refrigerator
//
// Created by chuxu on 2017/10/7 下午 10:01:08.
// Copyright 2017年 Misaka. All rights reserved.
//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[6][6],minn=18;
int r[17], c[17],R[17],C[17];
bool judge()
{
	int i, j;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (a[i][j] != 0)
				return 0;
	return 1;
}

void flip(int x, int y)
{
	int i;
	for (i = 0; i<4; i++)
		a[x][i] = !a[x][i];
	for (i = 0; i<4; i++)
		a[i][y] = !a[i][y];
	a[x][y] = !a[x][y];
}

void dfs(int cur,int step)
{
	if (cur == 16)
	{
		if (judge() && minn > step)
		{
			minn = step;
			for (int i = 0; i < minn; i++)
			{
				R[i] = r[i];
				C[i] = c[i];
			}
		}
		return;
	}
	flip(cur / 4, cur % 4);	//要做的事情
	r[step] = cur / 4;
	c[step] = cur % 4;
	dfs(cur + 1, step + 1);	//一个方向
	flip(cur / 4, cur % 4);	//取消更改
	dfs(cur + 1, step);		//另一个方向
}

int main()
{
	char b[6][6];
	int sum = 0;
	for (int i = 0; i < 4; i++) /*存入矩阵的信息*/
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == '+')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
		getchar();
	}
	dfs(0,0);
	cout << minn << endl;
	for (int i = 0; i<minn; i++)
		cout << R[i] + 1 << " " << C[i] + 1 << endl;
	return 0;
}

//void Next_permutation(int step, int n)
//{
//	int i, j;
//	if (step == n)
//	{
//		for (i = 0; i<n; i++)
//			cout << A[i] << " ";
//		cout << endl;
//		return;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		bool flag = true;
//		for (j = 0; j<step; j++)
//			if (i == A[j])
//			{
//				flag = false;
//				break;
//			}
//		if (flag)
//		{
//			A[step] = i;
//			Next_permutation(step + 1, n);
//		}
//	}
//}
