#include <bits/stdc++.h>
using namespace std;
int dis[(1 << 20)], ans, maxn = 0, n, k;
queue<int> que;

void print(int a)
{
	int b[k + 1];
	for (int i = 0; i < k; i++)
	{
		b[i] = a % 2;
		a /= 2;
	}
	for (int i = k - 1; i >= 0; i--)
		cout << b[i];
	cout << endl;
}

int main()
{
	memset(dis, -1, sizeof(dis));
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		bitset<32> b;//注意如果按照正序存放，输出也要正序！
		cin >> b;
		int tmp = b.to_ulong();
		que.push(tmp);
		dis[tmp] = 0;
	}
	while (!que.empty())
	{
		int tmp = que.front();
		que.pop();
		for (int i = 0; i < k; i++)
		{
			int next = tmp ^ (1 << i);
			if (dis[next] == -1)
			{
				dis[next] = dis[tmp] + 1;
				que.push(next);
				if (maxn < dis[next])
				{
					maxn = dis[next];
					ans = next;
				}
			}
		}
	}
	print(ans);
}
//bfs找到最远的值，注意二进制处理
