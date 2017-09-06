#include <iostream>
#include <algorithm>
using namespace std;

int CaculateWeekDay(int y, int m, int d)
{
	if (m == 1 || m == 2) 
	{
		m += 12;
		y--;
	}
	int iWeek = ((y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + 13 * (m + 1) / 5 + d) % 7;
	return iWeek;
}

bool isday(int year, int month, int day)
{
	if (month > 12)
		return false;
	else if (day>31)
		return false;
	else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return false;
	else if (month == 2 && day == 30)
		return false;
	else if (month == 2 && day == 29)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return true;
		else
			return false;
	}
	else
		return true;
}

int main()
{
	int year, month, day, t;
	cin >> t;
	while (t--)
	{
		scanf("%d-%d-%d",&year,&month,&day);
		int iweek = CaculateWeekDay(year, month, day);
		//cout << iweek<< endl;
		int iweek2 = -1;
		while (iweek2 != iweek)
		{
			year++;
			if (!isday(year, month, day))
				continue;
			iweek2 = CaculateWeekDay(year, month, day);
		}
		//cout << year << endl;
		cout << iweek2 << endl;
	}
	return 0;
}

