#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i, start;
	int a[101] = { 0 }, b[101] = { 0 }, c[101] = { 0 };
	char as[101], bs[101];
	gets_s(as);
	gets_s(bs);
	for (i = 0; i < strlen(as); i++)
	{
		a[i] = as[strlen(as) - i - 1] - '0';
	}
	for (i = 0; i < strlen(bs); i++)
	{
		b[i] = bs[strlen(bs) - i - 1] - '0';
	}
	for (i = 0; i < (strlen(as) > strlen(bs) ? strlen(as) : strlen(bs)); i++)
	{
		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{
			c[i + 1]++;
			c[i] -= 10;
		}
	}
	start = i;
	if (c[start] == 0)
		start--;
	for (i = start; i >= 0; i--)
	{
		printf("%d", c[i]);
	}
	return 0;
}