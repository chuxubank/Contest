#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a, b;
	double min_price = DBL_MAX;
	cin >> n >> m;
	while(n--)
	{
		cin >> a >> b;
		double c = a * 1.0 / b;
		min_price = min(c, min_price);
	}
	cout << fixed << setprecision(10) << min_price * m << endl;
	return 0;
}