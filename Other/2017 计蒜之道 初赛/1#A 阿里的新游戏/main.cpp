#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int red[7][7];
	int ming[7][7];
	int n, m;
	cin >> n >> m;
	memset(red, sizeof(red), 0);
	memset(ming, sizeof(ming), 0);
	while(n--)
	{
		int i, j;
		cin >> i >> j;
		red[i + 3][j + 3] = 1;
	}
	while(m--)
	{
		int i, j;
		cin >> i >> j;
		ming[i + 3][j + 3] = 1;
	}
	int countRed;
	for(int i = 0; i < 6; i++)
	{
		int count = 0;
		if(i == 3)
			continue;
		for(int j = 0; j < 6; j++)
		{
			if(red[i][j] == 1)
				count++;
			if(count == 3)
			{
				countRed++;
				break;
			}
		}
	}
	cout << countRed;
	return 0;
}

