#include <stdio.h>
#include <string.h>
int findstring1(int j, int k, char* a, char* b)
{
	int i, flag = 1, i1;
	for (i = j, i1 = 0; i < k, i1<strlen(a); i++, i1++)
	{
		if (a[i1] != b[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int findstring2(int j, int k, char* a, char* b)
{
	int i, flag = 1, i1;
	for (i = j, i1 = 0; i < k, i1<strlen(a); i++, i1++)
	{
		if (a[i1] != b[i] )
		{
			if (a[i1] != b[i] + 32 && a[i1] != b[i] - 32)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}
int main()
{
	int i, n, j, k;
	char a[101];
	int flag, f = 0;
	char b[101][101];
	scanf("%s", a);
	scanf("%d", &flag);
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		scanf("%s", b[i]);
	}
	if (flag == 1)
	{
		for (i = 0; i<n; i++)
		{
			f = 0;
			for (j = 0; j<strlen(b[i]); j++)
			{
				for (k = j + strlen(a); k <= strlen(b[i]); k++)
				{
					if (findstring1(j, k, a, b[i]) == 1)
					{
						f = 1;
						break;
					}
				}
				if (f == 1)
					break;
			}
			if (f == 1)
			{
				printf("%s\n", b[i]);
			}
		}
	}
	else
	{
		for (i = 0; i<n; i++)
		{
			f = 0;
			for (j = 0; j<strlen(b[i]); j++)
			{
				for (k = j + strlen(a); k <= strlen(b[i]); k++)
				{
					if (findstring2(j, k, a, b[i]) == 1)
					{
						f = 1;
						break;
					}
				}
				if (f == 1)
					break;
			}
			if (f == 1)
			{
				printf("%s\n", b[i]);
			}
		}
	}
	return 0;
}