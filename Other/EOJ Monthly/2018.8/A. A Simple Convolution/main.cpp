#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, h, w;
int image[maxn][maxn];
int kernel[maxn][maxn];
int out[maxn][maxn];

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> image[i][j];
		}
	}
	cin >> h >> w;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			cin >> kernel[i][j];
		}
	}
	for(int i = 0; i < n - h + 1; i++)
	{
		for(int j = 0; j < m - w + 1; j++)
		{
			int sum = 0;
			for(int ii = 0; ii < h; ii++)
			{
				for(int jj = 0; jj < w; jj++)
				{
					int data = image[i + ii][j + jj];
					int coeff = kernel[ii][jj];
					sum += data * coeff;
				}
			}
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}