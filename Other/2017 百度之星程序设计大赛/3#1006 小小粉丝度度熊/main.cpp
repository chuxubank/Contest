#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e9;
char retable[maxn + 5], temptable[maxn + 5];
int n, m, l[100005], r[100005], tempm, tempresult;

int calcondays()
{
	int i, res = 0;
	for(i = 1; i <= 1000000001; i++)
	{
		if(temptable[i] != 0)
			break;
	}
	for(; i <= 1000000001; i++)
	{
		if(temptable[i] == '1')
			res++;
		else
			break;
	}
	return res;
}

int main()
{
	while(scanf("%d %d", &n, &m) == 2)
	{
		int max1 = 0;
		memset(retable, 0, sizeof(retable));
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d", &l[i], &r[i]);
			for(int j = l[i]; j <= r[i]; j++)
			{
				retable[j] = '1';
			}
		}
		for(int i = 1; i <= n; i++)
		{
			tempresult = 0;
			tempm = m;
			strcpy(temptable, retable);
			for(int j = r[i]; j <= 1000000001; j++)
			{
				if(temptable[j] != '1' && tempm > 0)
				{
					temptable[j] = '1';
					tempm--;
				}
				tempresult = calcondays();
				if(tempresult >= max1)
					max1 = tempresult;
			}
		}
		cout << max1 << endl;
	}
	return 0;
}