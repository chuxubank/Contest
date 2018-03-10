#include <bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int n, m, src;
vector<pair<int, int> > g[maxn];
int dist[maxn];
bool inQue[maxn];
queue<int> que;
int spfa(void);

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int f, t, l;
		cin >> f >> t >> l;
		g[f].push_back(make_pair(t, l));
	}
	src = 1;
	spfa();
	for(int i = 2; i <= n; i++)
	{
		cout << dist[i] << endl;
	}
	return 0;
}

int spfa()
{
	memset(dist, 63, sizeof(dist));
	dist[src] = 0;
	while(!que.empty())
		que.pop();
	que.push(src);
	inQue[src] = true;
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		for(int i = 0; i < g[u].size(); i++)
		{
			if(dist[u] + g[u][i].second < dist[g[u][i].first])
			{
				dist[g[u][i].first] = dist[u] + g[u][i].second;
				if(!inQue[g[u][i].first])
				{
					inQue[g[u][i].first] = true;
					que.push(g[u][i].first);
				}
			}
		}
		inQue[u] = false;
	}
	return 0;
}

//SPFA模版题目
//SPFA其实是BF的队列优化，求单源最短路
//只要最短路存在，一定能求出