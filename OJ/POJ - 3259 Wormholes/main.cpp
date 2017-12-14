#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int maxn = 505;
struct Edge
{
	int from, to, dist;
	Edge(int u, int v, int d) : from(u), to(v), dist(d){}
};

vector<Edge> edges;
vector<int> G[maxn];
int d[maxn];
bool inq[maxn];
int cnt[maxn];
int n, m, w;
int s, e, t;

void init(int n)
{
	for (int i = 0; i < n; i++)
		G[i].clear();
	edges.clear();
}

void addedge(int from, int to, int dist)
{
	edges.push_back(Edge(from, to, dist));
	G[from].push_back(edges.size() - 1);
}

//SPFA
bool bellman_ford(int s)
{
	queue<int> Q;
	memset(inq, 0, sizeof(inq));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++)
		d[i] = INT_MAX;
	d[s] = 0;
	inq[s] = true;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++)
		{
			Edge& edge = edges[G[u][i]];
			if (d[u] < INT_MAX && d[edge.to] > d[u] + edge.dist)
			{
				d[edge.to] = d[u] + edge.dist;
				if (!inq[edge.to])
				{
					Q.push(edge.to);
					inq[edge.to] = true;
					if (++cnt[edge.to] > n)
						return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	int f;
	cin >> f;
	while (f--)
	{
		cin >> n >> m >> w;
		init(n);
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			addedge(s - 1, e - 1, t);    //BF默认从零开始
			addedge(e - 1, s - 1, t);
		}
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			addedge(s - 1, e - 1, -t);
		}
		if (bellman_ford(0) == false)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
