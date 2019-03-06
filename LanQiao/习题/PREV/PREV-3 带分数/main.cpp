/*
问题描述
100 可以表示为带分数的形式：100 = 3 + 69258 / 714。

还可以表示为：100 = 82 + 3546 / 197。

注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

类似这样的带分数，100 有 11 种表示法。

输入格式
从标准输入读入一个正整数N (N<1000*1000)

输出格式
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。

注意：不要求输出每个表示，只统计有多少表示法！

样例输入1
100
样例输出1
11
样例输入2
105
样例输出2
6
*/

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