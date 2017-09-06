#include<stdio.h>
int main()
{
	int i,j,k, y, d;
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d %d", &y,&d);
	if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
		month[2]=29;
	for (i = 1, k = 1, j = 1; i <= d; i++)
	{
		if (k > month[j])
		{
			j++;
			k = 2;
		}
		else
			k++;
	}
	printf("%d\n%d\n", j, k-1);
	return 0;
}