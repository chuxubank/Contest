//
// main.cpp
// UVA - 1587 Box
//
// Created by chuxu on 2017/9/5 下午 10:00:31.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e9 + 7;
int main()
{
	int t,height,width,i=0;
	int face[7][3];
	while (cin >> height >> width)
	{
		i++;
		face[i][1] = height;
		face[i][2] = width;
		if (i == 6)
		{
			int pair = 0;
			i = 0;
			for (int j = 1; j <= 6; j++)
			{
				for (int k = j + 1; k <= 6; k++)
				{
					if (face[j][1] == face[k][1] && face[j][2] == face[k][2] || face[j][1] == face[k][2] && face[j][2] == face[k][1])
					{
						pair++;
						face[j][1] = -1;
						face[k][1] = -1;
					}
				}
			}
			if (pair == 3)
				cout << "POSSIBLE" << endl;
			else
				cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}