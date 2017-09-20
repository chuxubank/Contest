//
// main.cpp
// UVA - 213 Message Decoding
//
// Created by chuxu on 2017/9/13 下午 1:50:20.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 1e9 + 7;
int code[8][1 << 8];
int readchar()
{
	for (;;)
	{
		int ch = getchar();
		if (ch != '\n' && ch != '\r')
			return ch;
	}
}

int readint(int c)
{
	int v = 0;
	while (c--)
		v = v * 2 + readchar() - '0';
	return v;
}

int readcodes()
{
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len <= 7; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			int ch = getchar();
			if (ch == EOF) return 0;
			if (ch == '\n' || ch == '\r') return 1;
			code[len][i] = ch;
		}
	}
	return 1;
}

int main()
{
	while (readcodes())
	{
		for (;;)
		{
			int len = readint(3);
			if (len == 0) break;
			for (;;)
			{
				int v = readint(len);
				if (v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}