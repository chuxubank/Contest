#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n = 0, i;
	char a, b[3], c[5], d;
	scanf("%c-%3s-%5s-%c", &a, b, c, &d);
	n = 1 * (a - '0');
	for (i = 1; i <= 3; i++)
	{
		n += (b[i - 1] - '0')*(i + 1);
	}
	for (i = 4; i <= 8; i++)
	{
		n += (c[i - 4] - '0')*(i + 1);
	}
	if (n % 11 != 10)
	{
		if (n % 11 == d - '0')
			printf("Right\n");
		else
			printf("%c-%3s-%5s-%d\n", a, b, c, n % 11);
	}
	else
	{
		if (d == 'X')
			printf("Right\n");
		else
			printf("%c-%3s-%5s-X\n", a, b, c);
	}
	return 0;
}