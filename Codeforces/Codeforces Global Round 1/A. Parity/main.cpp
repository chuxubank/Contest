#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int b, k, odd_num = 0;
	cin >> b >> k;
	int a[k];
	for (int i = 1; i <= k; i++)
	{
		cin >> a[i];
		if (a[i] % 2 == 1 && b % 2 == 1 && i != k)
			odd_num++;
	}
	if (a[k] % 2 == 1)
		odd_num++;
	if (odd_num % 2 == 0)
		cout << "even";
	else
		cout << "odd";
	return 0;
}