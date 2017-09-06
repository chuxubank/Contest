#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 1e9 + 7;
char a[6][6];
int flag = 0, bi, bj, t = 0;
char com;


int main()
{
	while (1)
	{
		flag = 0;
		for (int i = 0; i<5; i++)
		{
			fgets(a[i], 7, stdin);
			if (a[0][0] == 'Z')
				return 0;
			for (int j = 0; j<5; j++)
			{
				if (a[i][j] == '\n')
					a[i][j] = ' ';
				if (a[i][j] == ' ')
				{
					bi = i;
					bj = j;
				}
			}
		}
		while ((com = getchar()) != '0')
		{
			switch (com)
			{
			case 'A':
				if (bi - 1 < 0)
				{
					flag = 1;
					break;
				}
				a[bi][bj] = a[bi - 1][bj];
				bi--;
				break;
			case 'B':
				if (bi + 1 > 4)
				{
					flag = 1;
					break;
				}
				a[bi][bj] = a[bi + 1][bj];
				bi++;
				break;
			case 'L':
				if (bj - 1 < 0)
				{
					flag = 1;
					break;
				}
				a[bi][bj] = a[bi][bj - 1];
				bj--;
				break;
			case 'R':
				if (bj + 1 > 4)
				{
					flag = 1;
					break;
				}
				a[bi][bj] = a[bi][bj + 1];
				bj++;
				break;
			}
		}
		getchar();
		if (t++)
			cout << endl;
		cout << "Puzzle #" << t << ":" << endl;
		if (flag)
			cout << "This puzzle has no final configuration." << endl;
		else
		{
			a[bi][bj] = ' ';
			for (int i = 0; i<5; i++)
			{
				for (int j = 0; j<5; j++)
				{
					if(j==0)
						printf("%c", a[i][j]);
					else
						printf(" %c", a[i][j]);
				}
				cout << endl;
			}
		}
	}
	return 0;
}
