#include <bits/stdc++.h>
using namespace std;
const int INF=INT_MAX;
const int MaxN=1005;
int dis[MaxN],g[MaxN][MaxN],N;
bool v[MaxN];

void dijkstra()
{
	for(int i=1;i<=N;++i)
		dis[i]=INF;
	dis[1]=0;
	memset(v,0,sizeof v);
	for(int i=1;i<=N;++i)
	{
		int mark=-1,mindis=INF;
		for(int j=1;j<=N;j++)
		{
			if(!v[j] && dis[j]<mindis)
			{
				mindis=dis[j];
				mark=j;
			}
		}
		v[mark]=1;
		for(int j=1;j<=N;++j)
		{
			if(!v[j])
			{
				dis[j]=min(dis[j],dis[mark]+g[mark][j]);
			}
		}
	}
}

int main()
{
	int n,m;
	int t, a, b, c;
	cin>>n>>m;
	N=n;
	for(int i=0;i<m;i++)
	{
		cin>>t>>a>>b>>c;
		g[a][b]=c;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
	dijkstra();
	cout<<dis[n]<<endl;
}
