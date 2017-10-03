#include <cstdio>
#include <cmath>
const int mod=998244353;
int m, b, c, xi, i, x[52],ca=0;
long long n;

long long sumx(int x[52],int i)
{
	long long ret = 0;
	for (int j = 0; j < i; j++)
	{
		ret += x[j];
	}
	return ret;
}
int main()
{
	while (scanf("%d %d %d", &m, &b, &c) == 3)
	{
		scanf("%d", &n);
		xi = 0;
		i = 0;
		while (xi<=pow(b,i)-c && sumx(x,i)<n)
		{
			xi++;
			x[i] = xi;
			i++;
		}
		printf("Case #%d:%d", ++ca, i % mod);
	}
}