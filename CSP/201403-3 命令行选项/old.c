#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	struct options
	{
		char letter;
		int useable;
		char parameter[21][257];
		int has_p;
		int usedline[21];
	}o[27];
	char names[53],a[21][257];
	int i,i1=0, j = 0, k, n, flag = 0, flag2 = 0,m;
	for (i = 1; i <= 26; i++)
	{
		o[i].has_p = 0;
		o[i].letter = i + 96;
		strcpy(o[i].parameter,"\0");
		o[i].useable = 0;
		for (j = 1; j <= 20; j++)
		{
			o[i].usedline[j] = 0;
		}
	}
	gets(names);
	i = 0;
	while (names[i]!='\0')
	{
		if (names[i] == ':')
		{
			o[names[i - 1] - 'a' + 1].has_p = 1;
		}
		else
		{
			o[names[i] - 'a' + 1].useable = 1;
		}
		i++;
	}
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(&a[i-1][257]);
	}
	for (i = 0; i < n; i++)
	{
		k = strlen(&a[i - 1][257]);
		j = 0;
		while (a[i][j] != ' '&&a[i][j]!='\0')
			j++;
		j++;	
		while (1)
		{
			flag = 0; flag2 = 0;
			if (a[i][j] == '-' && o[a[i][j + 1] - 'a' + 1].useable == 1 && o[a[i][j + 1] - 'a' + 1].has_p == 0)
			{
				flag = 1;
				o[a[i][j + 1] - 'a' + 1].usedline[i + 1] = 1;
				j = j + 3;
				continue;
			}
			else if (a[i][j] == '-' && o[a[i][j + 1] - 'a' + 1].useable == 1 && o[a[i][j + 1] - 'a' + 1].has_p == 1)
			{
				flag2 = 1;
				o[a[i][j + 1] - 'a' + 1].usedline[i + 1] = 1;
				j = j + 3;
			}
			if (flag2 == 1)
			{
				i1=0;
				m = a[i][j - 2] - 'a' + 1;
				while (a[i][j] != ' ' && a[i][j]!='\0')
				{
					o[m].parameter[i][i1] = a[i][j];
					j++;
					i1++;
				}
				o[m].parameter[i][i1] = '\0';
				j++;
			}
			if (j>k - 3 || flag == 0 && flag2 == 0)
				break;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("Case %d: ",i+1);
		for (j = 1; j <= 26; j++)
		{
			if (o[j].usedline[i + 1] == 1 && o[j].has_p == 0)
				printf("-%c ", o[j].letter);
			if (o[j].usedline[i + 1] == 1 && o[j].has_p == 1)
				printf("-%c %s ", o[j].letter,o[j].parameter[i]);
		}
		printf("\n");
	}
}