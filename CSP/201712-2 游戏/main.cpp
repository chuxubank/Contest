#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		a.push_back(i);
	}
	int number = 1, i = 0;
	while (a.size() > 2)
	{
		int now = i % (a.size());
		if (number % k == 0 || number % 10 == k)
		{
			a.erase(a.begin() + now);
			i--;
		}
		i++;
		number++;
	}
	cout << a[0] << endl;
	return 0;
}
