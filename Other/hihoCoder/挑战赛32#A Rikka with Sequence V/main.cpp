#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (j < n)
			a.insert(a.begin() + i, ++j);
		if (j < n)
			a.insert(a.begin() + i + 1, ++j);
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
