#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	for(int i = 0; i < (int)(n * 1.0 / 2 + 0.5); i++)
	{
		for(int i = 0; i < n; i++)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}