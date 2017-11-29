#include <stdio.h>
int i, j, k, a, b, c, y1, y2, flag = 0, week;
int a1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
struct months
{
	int days;
	int day[32];
};
struct years
{
	int flag_y;
	struct months month[13];
}year[2051];
int main()
{
	year[1850].month[1].day[1] = 2;
	for (i = 1850; i <= 2050; i++)
	{
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
			year[i].flag_y = 1;
		for (j = 1; j <= 12; j++)
		{
			year[i].month[j].days = a1[j];
			if (year[i].flag_y == 1)
				year[i].month[2].days=29;
			if (j != 1)
			{
				year[i].month[j].day[1] = (year[i].month[j - 1].day[1] + year[i].month[j - 1].days) % 7;
			}
			for (k = 2; k <= year[i].month[j].days; k++)
			{
				year[i].month[j].day[k] = (year[i].month[j].day[k - 1] + 1) % 7;
			}
		}
		year[i + 1].month[1].day[1] = (year[i].month[12].day[31] + 1) % 7;
	}
	scanf("%d %d %d %d %d", &a, &b, &c, &y1, &y2);
	for (i = y1; i <= y2; i++)
	{
		flag = 0;
		week = 0;
		j = a;
		for (k = 1; k <= year[i].month[j].days; k++)
		{
			if (year[i].month[j].day[k] == c%7)
				week++;
			if (week == b)
			{
				flag = 1;
				printf("%d/%02d/%02d\n", i, j, k);
				break;
			}
		}

		if (flag == 0)
			printf("none\n");
	}
	return 0;
}