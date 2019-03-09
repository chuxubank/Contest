#include <bits/stdc++.h>
using namespace std;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mo[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int year = 1777, month = 4, day = 30;
    int count = 8113;
    for (int i = 1; i < count; i++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day < mo[month])
                day++;
            else
            {
                if (month < 12)
                    month++;
                else
                {
                    month = 1;
                    year++;
                }
                day = 1;
            }
        }
        else
        {
            if (day < mon[month])
                day++;
            else
            {
                if (month < 12)
                    month++;
                else
                {
                    month = 1;
                    year++;
                }
                day = 1;
            }
        }
    }
    printf("%2d-%02d-%2d\n", year, month, day);
    return 0;
}

// 1799-07-16