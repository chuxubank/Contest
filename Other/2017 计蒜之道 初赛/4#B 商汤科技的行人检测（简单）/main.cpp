#include <iostream>
using namespace std;
long a[100001][5];

int main()
{
	long n;
	long x, y;
	long count = 0;
	cin >> n;
	for(long i = 0; i < n; i++)
	{
		for(long j = 0; j < 4; j++)
			cin >> a[i][j];
	}
	for(long i = 0; i < n; i++)
	{
		x = a[i][2] - a[i][0];
		y = a[i][3] - a[i][1];
		for(long j = 1; j < n; j++)
		{
			if((a[j][2] - a[j][0] == x) && (a[j][3] - a[j][1] == y))
				count++;
			else if(count * 2 >= n)
			{
				cout << x << ' ' << y;
				return 0;
			}
			else
				continue;
		}
	}
	cout << x << ' ' << y;
	return 0;
}
