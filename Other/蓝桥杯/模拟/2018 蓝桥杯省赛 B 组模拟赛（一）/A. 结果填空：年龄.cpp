#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count = 0;
	for(int i = 10; i < 100; i++)
	{
		for(int j = 10; j < 100; j++)
		{
			if((i % 10 + i / 10) * 3 == j && (j % 10 + j / 10) * 2 == i)
			{
				count++;
				cout << i << " " << j << endl;
			}
		}
	}
	cout << count;
	return 0;
}