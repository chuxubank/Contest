#include <stdio.h>
int main()
{
	long long n;
	long long output;
	scanf("%lld", &n);
	if (n % 2 == 0)
	{
		if (n % 3 != 0)
			output = n*(n - 1)*(n - 3);
		else
			output = (n - 1)*(n - 2)*(n - 3);
	}
	else
		output = n*(n - 1)*(n - 2);
	printf("%lld", output);
	return 0;
}