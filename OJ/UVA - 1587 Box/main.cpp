//
// main.cpp
// UVA - 1587 Box
//
// Created by chuxu on 2017/9/5 下午 10:00:31.
// Copyright 2017年 Misaka. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e9 + 7;

struct Face {
	int height;
	int width;
	bool operator==(Face& rhs) const 
	{
		return (height == rhs.height && width == rhs.width);
	}
}face[7];

bool compar(struct Face a, struct Face b)
{
	if (a.width == b.width)
		return a.height < b.height;
	else
		return a.width < b.width;
}

int main()
{
	int i=1;
	while (cin >> face[i].height >> face[i].width)
	{
		if (face[i].height < face[i].width)
			swap(face[i].height, face[i].width);
		if (i == 6)
		{
			i = 0;
			sort(face + 1, face + 7, compar);
			if(face[1]==face[2] && face[3]==face[4] && face[5]==face[6] && face[1].width==face[3].width && face[1].height==face[5].width && face[3].height==face[5].height)
				cout << "POSSIBLE" << endl;
			else
				cout << "IMPOSSIBLE" << endl;	
		}
		i++;
	}
	return 0;
}