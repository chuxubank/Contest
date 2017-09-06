#include<cstdio>
using namespace std;
int main()
{
	int ca=0,n;
	long long k;
	while (~scanf("%d %lld", &n, &k))
	{
		if (k <= n)
			printf("Case #%d: %lld\n", ++ca, k);
		else
		{
			k -= n;
			long long t = k / (n - 1);
			k %= n - 1;
			if (!k) 
				printf("Case #%d: %d\n", ++ca, t & 1 ? n - 1 : n);
			else 
				printf("Case #%d: %lld\n", ++ca, k);
		}
	}
	return 0;
}