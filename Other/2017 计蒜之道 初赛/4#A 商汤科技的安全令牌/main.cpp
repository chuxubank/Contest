#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int a[101][101];
int count1 = 0;

void fullcol()
{
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == a[i + 1][j] && a[i][j] == 0)
			{
				a[i][j] = 1;
				a[i + 1][j] = 1;
				count1++;
			}
		}
	}
}

void fullrow()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			if(a[i][j] == a[i][j + 1] && a[i][j] == 0)
			{
				a[i][j] = 1;
				a[i][j + 1] = 1;
				count1++;
			}
		}
	}
}

int main()
{
	memset(a, sizeof(a), 1);
	int i, j, l;
	int d, c;

	cin >> n >> m >> k;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			a[i][j] = 0;
		}
	}
	for(l = 0; l < k; l++)
	{
		cin >> d >> c;
		if(d)
		{
			for(i = 1; i <= n; i++)
				a[i][c] = 1;
		}
		else
			for(j = 1; j <= m; j++)
				a[c][j] = 1;
	}
	fullcol();
	fullrow();
	cout << count1;
	return 0;
}

