#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, k, m, n, varlen[101], flag;
	char input[101][80];
	char varstr[101][100];
	char varname[101][80];
	char c[101][180];
	char *p1,*p2,*p3;
	scanf("%d %d", &m, &n);
	getchar();
	for (i = 0; i < m; i++)
	{
		gets(input[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%s", varname[i]);
		gets(varstr[i]);
		p1 = strchr(varstr[i], '\"');
		if (p1)
		{
			strcpy(varstr[i], p1+1);
			varstr[i][strlen(varstr[i]) - 1] = '\0';
			varlen[i] = strlen(varstr[i]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (k = 0; k < n; k++)
		{
			flag = 0;
			while (1)
			{
				p1 = strstr(input[i], "{{ ");
				p2 = strstr(input[i], varname[k]);
				p3 = strstr(input[i], " }}");
				if (p1 + 3 == p2 && p2 + strlen(varname[k]) == p3 && p1 && p2 && p3)
				{
					strcat(varstr[k], p3 + 3);
					strcpy(p1, varstr[k]);
				}
				varstr[k][varlen[k]] = '\0';
				p2 = strstr(input[i], varname[k]);
				p1 = strstr(input[i], "{{ ");
				p3 = strstr(input[i], " }}");
				if (!(p1 + 3 == p2 && p2 + strlen(varname[k]) == p3 && p1 && p2 && p3))
				{
					break;
				}
			}
			for (j = 0; j < n; j++)
			{
				if (!strstr(input[i], "{{ "))
				{
					flag = 1;
					break;
				}
				if (strstr(input[i], "{{ ") && strstr(input[i], " }}") && strstr(input[i], varname[j]))
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				p1 = strstr(input[i], "{{ ");
				p3 = strstr(input[i], " }}");
				strcpy(p1, p3 + 3);
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		puts(input[i]);
	}
	return 0;
}