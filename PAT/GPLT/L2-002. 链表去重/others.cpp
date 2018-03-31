#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	int next;
} input[100005];

int vis[100005];
int ans[100005], res[100005];

int main()
{
	int adress, n;
	scanf("%d%d", &adress, &n);
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		scanf("%d%d", &input[temp].val, &input[temp].next);
	}
	int pos_ans = 0;
	int pos_res = 0;
	for(int i = adress; i != -1; i = input[i].next)
	{
		int num = abs(input[i].val);
		if(!vis[num])
			vis[num] = 1, ans[pos_ans++] = i;
		else
			res[pos_res++] = i;
	}
	printf("%05d %d ", ans[0], input[ans[0]].val);
	for(int i = 1; i < pos_ans; i++)
	{
		printf("%05d\n", ans[i]);
		printf("%05d %d ", ans[i], input[ans[i]].val);
	}
	printf("-1\n");
	if(pos_res)
	{
		printf("%05d %d ", res[0], input[res[0]].val);
		for(int i = 1; i < pos_res; i++)
		{
			printf("%05d\n", res[i]);
			printf("%05d %d ", res[i], input[res[i]].val);
		}
		printf("-1\n");
	}
}

//利用vis数组判断是否出现过，避免查找