#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
	//1不是素数
	if(num == 1)
		return 0;
	//两个较小数另外处理
	if(num == 2 || num == 3)
		return 1;
	//不在6的倍数两侧的一定不是质数
	if(num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	//在6的倍数两侧的也可能不是质数
	for(int i = 5; i <= tmp; i += 6)
		if(num % i == 0 || num % (i + 2) == 0)
			return 0;
	//排除所有，剩余的是质数
	return 1;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int query;
		cin >> query;
		if(isPrime(query))
		{
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}