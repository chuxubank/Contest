//WRONG ANSWER
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;

bool isPrime(int num)
{
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
	vector<ll> factorial(maxn + 1);
	factorial[0] = factorial[1] = 1;
	for(int i = 2; i <= maxn; i++)
		factorial[i] = (factorial[i - 1] * i);
	// for(int i = 0; i <= maxn; i++)
	//  cout << factorial[i] << endl;
	ll n;
	cin >> n;
	if(isPrime(n))
	{
		cout << 1 << endl
		     << n;
		return 0;
	}
	int len = lower_bound(factorial.begin(), factorial.end(), n) - factorial.begin();
	// cout << "len=" << len << endl;
	int begin = 0;
	for(; len >= 1; len--)
	{
		bool flag = false;
		for(int i = 1; i <= maxn - len; i++)
		{
			if(n % (factorial[len + i] / factorial[i]) == 0)
			{
				begin = i;
				flag = true;
				break;
			}
		}
		if(flag == true)
			break;
	}
	if(len == 0)
	{
		for(int i = maxn; i < n; i++)
		{
			if(isPrime(i) && n % i == 0)
			{
				len = 1;
				begin = i - 1;
				break;
			}
		}
	}

	cout << len << endl;
	for(int i = 1; i <= len; i++)
	{
		cout << i + begin;
		if(i != len)
			cout << "*";
	}
	return 0;
}

//特殊的判断素数的方法
//前缀和求连续因数
//特殊情况 如果经过二重循环扫了一遍后len=0则说明len=1 且n由两个大于maxn的素数组成
//思路错误 反例22*23