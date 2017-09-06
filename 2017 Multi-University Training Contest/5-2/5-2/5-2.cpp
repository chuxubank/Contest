#include <iostream>
#include <cstdio>

using namespace std;

int dp[41];

void init()
{
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= 40; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];
}

int main()
{
	int T, len;
	init();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &len);
		printf("%d\n", dp[len]);
	}
	return 0;
}