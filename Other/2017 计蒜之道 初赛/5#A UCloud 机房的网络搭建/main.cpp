#include <iostream>
#include <algorithm>
using namespace std;
int c[101];

bool compare(int a, int b)
{
	return a > b;
}

int sumconned(int count)
{
	int sum = 0;
	for(int i = 0; i < count; i++)
	{
		sum += (c[i] - 1);
	}
	return sum + 1;
}

int main()
{
	int n, m;
	int count = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> c[i];
	}
	sort(c, c + m, compare);
	while(count < m && sumconned(count) < n)
	{
		count++;
	}

	if(sumconned(count) >= n)
		cout << count << endl;
	else
		cout << "Impossible" << endl;
}
