#include <iostream>
using namespace std;

const int mod = 1e9+7;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial()
{
	int i, j;
	for (i = 0; i <= MAXN; ++i)
	{
		C[0][i] = 0;
		C[i][0] = 1;
	}
	for (i = 1; i <= MAXN; ++i)
	{
		for (j = 1; j <= MAXN; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
}

int Combination(int n, int m)
{
	if (n > m)
		return C[n][m];
	else
		return C[m][n];
}

int main()
{
	int t,n,m;
	cin >> t;
	Initial();
	while (t--)
	{
		cin >> n >> m;
		cout << Combination(n, m) << endl;
	}
}