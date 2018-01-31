#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

bool is_u(int num)
{
	vector<int> a, b, c;

	bool result = false;
	while(num)
	{
		a.push_back(num % 10);
		num /= 10;
	}
	c = a;
	reverse(c.begin(), c.end());
	b = a;
	for(int i = 0; i < a.size() - 1; i++)
	{
		if(a[i] == a[i + 1])
			return false;
	}
	sort(b.begin(), b.end());
	if(b == a || b == c)
		return false;
	for(int i = 1; i < a.size() - 1; i++)
	{
		b = a;
		sort(b.begin(), b.begin() + i, cmp);
		sort(b.begin() + i, b.end());
		if(b == a)
			result = true;
	}
	return result;
}

int main()
{
	int count = 0;
	for(int i = 100; i <= 100000; i++)
	{
		if(is_u(i) == true)
		{
			count++;
			// cout<<i<<" ";
		}
	}
	cout << count << endl;
	return 0;
}