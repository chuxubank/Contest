#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char input[8][22];
int time[4];
int n;
int number(int begincol)
{
	string a = "0000000";
	for (int i = 0; i < 7; i++)
	{
		for (int j = begincol; j < begincol+4; j++)
		{
			if (input[i][j] == 'X'&&i == 0)
				a[0] = '1';
			if (input[i][j] == 'X'&&i == 1 && j == begincol + 3)
				a[1] = '1';
			if (input[i][j] == 'X'&&i == 4 && j == begincol + 3)
				a[2] = '1';
			if (input[i][j] == 'X'&&i == 6)
				a[3] = '1';
			if (input[i][j] == 'X'&&i == 4 && j == begincol)
				a[4] = '1';	
			if (input[i][j] == 'X'&&i == 1 && j == begincol)
				a[5] = '1';	
			if (input[i][j] == 'X'&&i == 3)
				a[6] = '1';
		}
	}
	if (a == "1111110")
	{
		return 0;
	}
	if (a == "0110000")
	{
		return 1;
	}
	if (a == "1101101")
	{
		return 2;
	}
	if (a == "1111001")
	{
		return 3;
	}
	if (a == "0110011")
	{
		return 4;
	}
	if (a == "1011011")
	{
		return 5;
	}
	if (a == "1011111")
	{
		return 6;
	}
	if (a == "1110000")
	{
		return 7;
	}
	if (a == "1111111")
	{
		return 8;
	}
	if (a == "1111011")
	{
		return 9;
	}
	return -1;
}
int main()
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gets_s(input[j]);
		}
		printf("%d", number(0));
		printf("%d", number(5));
		printf(":");
		printf("%d", number(12));
		printf("%d", number(17));
		printf("\n");
	}
}