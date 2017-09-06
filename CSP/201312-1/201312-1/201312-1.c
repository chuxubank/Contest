#include<stdio.h>
int main()
{
	int i,n,a[1000],flag=0,note;
	static int b[10000];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		b[a[i]]++;
	}
	for (i = 1; i <= 10000; i++)
	{
		if (b[i] > flag)
		{
			note = i;
			flag = b[i];
		}
	}
	printf("%d", note);
	return 0;
}