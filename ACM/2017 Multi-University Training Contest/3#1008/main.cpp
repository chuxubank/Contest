#include <cstdio>
#include <cmath>
const int mod = 1e9 + 7;
long long n, k,sum,i;
int main()
{
	while (scanf("%lld %lld", &n, &k) == 2)
	{
		while (i <= pow(n, k))
		{
			sum += (int)floor(sqrt(pow(n,k)/i)) % mod;
		}
		printf("%d", sum);
	}
}
