//
// main.cpp
// POJ - 2965 The Pilots Brothers' refigerator Math
//
// Created by chuxu on 2017/10/12 下午 9:02:41.
// Copyright 2017年 Misaka. All rights reserved.
//
#include<stdio.h>
#include<string.h>
int main()
{
	bool b[4][4]; int i, j, k, a = 0;
	char q; memset(b, 0, sizeof(b));
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%c", &q); if (q == '+') {
				for (k = 0; k < 4; k++) b[i][k] = !b[i][k], b[k][j] = !b[k][j];
				b[i][j] = !b[i][j];
			}
		}getchar();
	}
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (b[i][j]) a++;
	printf("%d\n", a);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (b[i][j]) printf("%d %d\n", i + 1, j + 1);
}