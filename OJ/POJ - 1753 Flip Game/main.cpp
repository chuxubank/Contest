#include <iostream>
#include <climits>
using namespace std;
int a[6][6];
int minn = INT_MAX;
bool judge() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (a[1][1] != a[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void flip(int x, int y)
{
	a[x][y] = -a[x][y];
	a[x - 1][y] = -a[x - 1][y];
	a[x][y - 1] = -a[x][y - 1];
	a[x + 1][y] = -a[x + 1][y];
	a[x][y + 1] = -a[x][y + 1];
}

void dfs(int cur, int count)
{
	if (cur==17)
	{
		if (judge() && minn>count)
			minn = count;
		return;
	}
	flip((cur - 1) / 4 + 1, (cur - 1) % 4 + 1);
	dfs(cur + 1, count + 1);
	flip((cur - 1) / 4 + 1, (cur - 1) % 4 + 1);
	dfs(cur + 1, count);
}
int main()
{
	char b[6][6];
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 'b')
				a[i][j] = 1;
			if (b[i][j] == 'w')
				a[i][j] = -1;
		}
		getchar();
	}
	dfs(0, 0);
	if (minn == INT_MAX)
		cout << "Impossible" << endl;
	else
		cout << minn << endl;
}
