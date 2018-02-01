#include<iostream>  
#include<algorithm>  
using namespace std;
long long d[105][105];
const int INF = 1000000007;
long long sum;
int main()
{
	int k, l, i, j, t;
	cin >> k >> l;
	for (j = 0; j < k; j++)
		d[1][j] = 1;
	for (i = 2; i <= l; i++)
		for (j = 0; j < k; j++)
			for (t = 0; t < k; t++)
				if (t != j - 1 && t != j + 1)
				{
					d[i][j] += d[i - 1][t];
					d[i][j] %= INF;
				}
	sum = 0;
	for (j = 1; j < k; j++)
	{
		sum += d[l][j];
		sum %= INF;
	}
	cout << sum << endl;
	return 0;
}