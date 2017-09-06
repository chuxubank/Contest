#include<stdio.h>
#include <string.h>
#include <iostream>
int n;
struct records
{
	int ord;
	char chocie[10];
	float money;
	int quentity;
	int useable;
	int del;
}record[5001];

long long numoftrades(float p0)
{
	int i;
	long long b = 0, s = 0;
	for (i = 1; i <= n; i++)
	{
		if (record[i].useable == 1 && record[i].chocie[0] == 'b'&&record[i].money >= p0)
			b += record[i].quentity;
		else if (record[i].useable == 1 && record[i].chocie[0] == 's'&&record[i].money <= p0)
			s += record[i].quentity;
	}
	return (b < s ? b : s);
}

int main()
{
	int i = 1;
	long long maxnum = 0;
	char choice[10];
	float p0, maxmoney = 0.00;
	long long num;
	while (std::cin >> choice)
	{
		if (choice[0] == 'b' || choice[0] == 's')
		{
			scanf("%f %d", &record[i].money, &record[i].quentity);
			strcpy(record[i].chocie, choice);
			record[i].ord = i;
			record[i].useable = 1;
			record[i].del = 0;
		}
		else
		{
			strcpy(record[i].chocie, choice);
			scanf("%d", &record[i].del);
			record[i].ord = i;
			record[i].useable = 0;
		}
		i++;
	}
	n = i - 1;
	for (i = 1; i <= n; i++)
	{
		if (record[i].chocie[0] == 'c')
		{
			record[record[i].del].useable = 0;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (record[i].useable == 1 && record[i].chocie[0] == 'b')
		{
			num = numoftrades(record[i].money);
			p0 = record[i].money;
			if (maxnum < num)
			{
				maxnum = num;
				maxmoney = p0;
			}
			if (maxnum == num)
				if (maxmoney < p0)
					maxmoney = p0;
		}
	}
	printf("%.2f ", maxmoney);
	std::cout << maxnum;
	return 0;
}