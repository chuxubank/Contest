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
	int number = 1, now = 0;
	while (a.size() != 1)
	{
		now = now % (a.size());
		if (number % k == 0 || number % 10 == k)
		{
			a.erase(a.begin() + now);
			now--;
		}
		now++;
		number++;
	}
	cout << a[0] << endl;
	return 0;
}
