#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count = 0;
	vector<bool> a(1001);
	for(int i = 1; i <= 1000; i++)
	{
		a[i] = true;
	}
	for(int i = 1; i <= 1000; i++)
	{
		if(i % 3 == 0)
			a[i] = !a[i];
		if(i % 5 == 0)
			a[i] = !a[i];
		if(i % 7 == 0)
			a[i] = !a[i];
	}
	for(int i = 1; i <= 1000; i++)
	{
		if(a[i] == true)
			count++;
	}
	cout << count;
	return 0;
}