#include<stdio.h>
int main()
{
	int i, j, n, start = 0, yu=0, shu;
	int A[99999] = { 0 };
	scanf("%d", &n);
	A[0] = 1;
	for (i = 2; i <= n; i++)
	{
		shu = 0;
		for (j = 0; j <= start; j++)
		{
			shu = A[j] * i + yu;
			A[j] = shu % 10;
			yu = shu / 10;
		}
		while (yu)
		{
			start++;
			A[start] = yu % 10;
			yu /= 10;
		}
	}
	for (i = start; i >= 0; i--)
	{
		printf("%d", A[i]);
	}
	return 0;
}