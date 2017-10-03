#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2005;
long long C[MAXN][MAXN];
long long P[MAXN][MAXN];
long long n, m;
void Initial()
{
	int i, j;
	for (i = 0; i <= MAXN; ++i)
	{
		C[0][i] = 0;
		C[i][0] = 1;
		P[0][i] = 0;
		P[i][0] = 1;
	}
	for (i = 1; i <= MAXN; ++i)
	{
		for (j = 1; j <= MAXN; ++j)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	for (i = 1; i <= MAXN; ++i)
	{
		for (j = 1; j <= MAXN; ++j)
			P[i][j] = (P[i - 1][j] + P[i - 1][j - 1]*j) % mod;
	}
}
int main()
{
	Initial();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cout << C[m][n]  << endl;
	}
}

