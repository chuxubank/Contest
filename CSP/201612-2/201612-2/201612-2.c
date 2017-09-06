#include <stdio.h>
int duty(int s)
{
	int a = s - 3500;
	if (a <= 0)
		return s;
	else if (a <= 1500)
		return s - (a)*3/100;
	else if (a>1500 && a <= 4500)
		return s - (1500 *3/100 + (a - 1500)/10);
	else if (a>4500 && a <= 9000)
		return s - (1500 *3/100 + 3000 /10 + (a - 4500)*2/10);
	else if (a>9000 && a <= 35000)
		return s - (1500 *3/100 + 3000 /10 + 4500 *2/10 + (a - 9000)/4);
	else if (a>35000 && a <= 55000)
		return s - (1500 *3/100 + 3000 /10 + 4500 *2/10 + 26000 /4 + (a - 35000)*3/10);
	else if (a>55000 && a <= 80000)
		return s - (1500 *3/100 + 3000 /10 + 4500 *2/10 + 26000 /4 + 20000 *3/10 + (a - 55000)*7/20);
	else if (a > 80000)
		return s - (1500 *3/100 + 3000 /10 + 4500 *2/10 + 26000 /4 + 20000 *3/10 + 25000 *7/20 + (a - 80000)*9/20);
}
int main()
{
	int t, s, min;
	scanf("%d", &t);
	if (t <= 3500)
		printf("%d", t);
	else
	{
		min = t / 100 * 100;
		s = min;
		while (duty(s) != t)
		{
			s += 100;
		}
		printf("%d", s);
	}
	return 0;
}
