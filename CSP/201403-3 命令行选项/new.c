#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	struct options
	{
		char letter;
		int useable;
		char parameter[22][257];
		int has_p;
		int usedline[22];
	}o[27];
	char names[55],a[22][257];
	int i,i1=0, j = 0, k, n, flag = 0, flag2 = 0,m;
	for (i = 1; i <= 26; i++)		//初始化结构
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
	scanf("%s",names);		//获取参数
	i = 0;
	while (names[i]!='\0')		//设置选项
	{
		if (names[i] == ':'&& names[i-1] >= 'a' && names[i-1] <= 'z')
		{
			o[names[i - 1] - 'a' + 1].has_p = 1;
		}
		else if(names[i]<='z' && names[i]>='a')
		{
			o[names[i] - 'a' + 1].useable = 1;
		}
		i++;
	}
	scanf("%d", &n);		//读取行数
	getchar();		//跳过换行符号
	for (i = 1; i <= n; i++)
	{
		gets(a[i]);
	}
	for (i = 1; i <= n; i++)
	{
		k = strlen(a[i]);
		j = 0;
		while (a[i][j] != ' ' && a[i][j]!='\0')		//跳过工具名
			j++;
		j++;
		while (1)		//分析每行
		{
			flag = 0; flag2 = 0;
			if (a[i][j] == '-' && o[a[i][j + 1] - 'a' + 1].useable == 1 && (a[i][j + 2] == ' '|| a[i][j + 2] == '\0') && o[a[i][j + 1] - 'a' + 1].has_p == 0)		//无参数命令处理
			{
				flag = 1;
				o[a[i][j + 1] - 'a' + 1].usedline[i] = 1;
				while (a[i][j] != ' '&&a[i][j] != '\0')
					j++;
				j++;
				continue;
			}
			else if (a[i][j] == '-' && o[a[i][j + 1] - 'a' + 1].useable == 1 && (a[i][j + 2] == ' ' || a[i][j + 2] == '\0') && o[a[i][j + 1] - 'a' + 1].has_p == 1)		//带参数命令处理
			{
				flag2 = 1;
				o[a[i][j + 1] - 'a' + 1].usedline[i] = 1;
				while (a[i][j] != ' '&&a[i][j] != '\0')
					j++;
				j++;
			}
			if (flag2 == 1)		//带参数则读取参数
			{
				i1=0;
				m = a[i][j - 2] - 'a' + 1;		//标记当前字符
				while (a[i][j] != ' ' && a[i][j]!='\0')		//记录参数
				{
					o[m].parameter[i][i1] = a[i][j];
					j++;
					i1++;
				}
				o[m].parameter[i][i1] = '\0';
				j++;
			}
			if (a[i][j] != '-' || o[a[i][j + 1] - 'a' + 1].useable == 0 || (a[i][j + 2] != ' ' && a[i][j + 2] != '\0'))		//跳过不合法命令
			{
				break;
			}
		}
	}
	for (i = 1; i <= n; i++)		//按字母序输出
	{
		printf("Case %d: ",i);
		for (j = 1; j <= 26; j++)
		{
			if (o[j].usedline[i] == 1 && o[j].has_p == 0)
				printf("-%c ", o[j].letter);
			if (o[j].usedline[i] == 1 && o[j].has_p == 1)
				printf("-%c %s ", o[j].letter,o[j].parameter[i]);
		}
		printf("\n");
	}
}
