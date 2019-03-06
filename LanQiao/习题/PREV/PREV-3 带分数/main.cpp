#include <bits/stdc++.h>
using namespace std;

// substr() is time consuming
int prase(char *arr, int start, int end)
{
	int ans = 0, t = 1;
	for (int i = end - 1; i >= start; i--)
	{
		ans += (arr[i] - '0') * t;
		t *= 10; //pow() is time consuming
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int add, num, den;
	int count = 0;
	char s[] = "123456789"; //char *s = "" is const
	do
	{
		for (int i = 1; i <= 7; i++)
		{
			add = prase(s, 0, i);
			if (add >= n)
				break;
			for (int j = i + (9 - i) / 2; j <= 8; j++)
			{
				num = prase(s, i, j);
				den = prase(s, j, 9);
				if (num % den == 0 && (add + num / den) == n)
					count++;
			}
		}
	} while (next_permutation(s, s + 9));
	cout << count;
	return 0;
}

// 1-9全排列，“插入” + /，验证算式，计数

// 1s = 10^8