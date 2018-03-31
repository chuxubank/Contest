#include <bits/stdc++.h>
using namespace std;
int n, m, s, d;
const int maxn = 505;
const int INF = 0x3f3f3f3f;
int num[maxn], wgt_org[maxn], wgt[maxn], dis[maxn], g[maxn][maxn], pre[maxn];
bool v[maxn];

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis);
	memset(v, 0, sizeof v);
	memset(pre, -1, sizeof pre);
	dis[s] = 0;
	num[s] = 1;
	wgt[s] = wgt_org[s];
	for(int i = 0; i < n; i++)
	{
		int k = -1, mindis = INF;
		for(int j = 0; j < n; j++)
		{
			if(!v[j] && dis[j] < mindis)
			{
				mindis = dis[j];
				k = j;
			}
		}
		v[k] = true;
		for(int j = 0; j < n; j++)
		{
			if(!v[j])
			{
				if(dis[j] > dis[k] + g[k][j])
				{
					dis[j] = dis[k] + g[k][j];
					wgt[j] = wgt[k] + wgt_org[j];
					num[j] = num[k];
					pre[j] = k;
				}
				else if(dis[j] == dis[k] + g[k][j])
				{
					num[j] += num[k];
					if(wgt[j] < wgt[k] + wgt_org[j])
					{
						wgt[j] = wgt[k] + wgt_org[j];
						pre[j] = k;
					}
				}
			}
		}
	}
}

vector<int> get_path()
{
	int cur = d;
	vector<int> path;
	while(cur != s)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	cin >> n >> m >> s >> d;
	for(int i = 0; i < n; i++)
	{
		cin >> wgt_org[i];
	}
	memset(g, 0x3f, sizeof g);
	for(int i = 0; i < m; i++)
	{
		int f, t, w;
		cin >> f >> t >> w;
		g[f][t] = w;
		g[t][f] = w;
	}
	dijkstra(s);
	cout << num[d] << " " << wgt[d] << endl;
	vector<int> path = get_path();
	cout << s;
	for(auto i : path)
	{
		cout << " " << i;
	}
	return 0;
}

//Dijkstra 记录路径 点权重
//INF 0x3f3f3f3f