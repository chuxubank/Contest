#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long  ll;
const ll INF=110000000000;
const int MAXN=200000+10;
struct Rec
{
    ll num,len;
    bool operator < (const Rec &a) const
    {
        return len>a.len;
    }
};
int u[MAXN*2],v[MAXN*2];
ll w[MAXN*2];
ll dis[MAXN/2],secondis[MAXN/2];
ll first[MAXN/2],mynext[MAXN*2];
int n,r;

void dijkstra()
{
    priority_queue<Rec> que;
    
    for (int i=1;i<n;i++)
    {
        dis[i]=INF;
        secondis[i]=INF;
    }
    dis[0]=0;
    secondis[0]=INF;
    
    Rec temp;
    temp.len=0;temp.num=0;
    que.push(temp);
    
    while (!que.empty())
    {
        Rec head=que.top();
        que.pop();
        if (head.len>secondis[head.num])
            continue;
        ll k=first[head.num];
        while (k!=-1)
        {
            ll d=head.len+w[k];
            if (dis[v[k]]>d)
            {
                swap(dis[v[k]],d);
                temp.len=dis[v[k]];
                temp.num=v[k];
                que.push(temp);
            }
            if (dis[v[k]]<d && secondis[v[k]]>d)
            {
                secondis[v[k]]=d;
                temp.len=secondis[v[k]];temp.num=v[k];
                que.push(temp);
            }
            k=mynext[k];
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&r);
        memset(first,-1,sizeof(first));
        for (int i=0;i<r;i++)
        {
            scanf("%d%d%lld",&u[i],&v[i],&w[i]);
            u[i]--;
            v[i]--;
            mynext[i]=first[u[i]];
            first[u[i]]=i;
            v[i+r]=u[i];
            u[i+r]=v[i];
            w[i+r]=w[i];
            mynext[i+r]=first[u[i+r]];
            first[u[i+r]]=i+r;
        }
        dijkstra();
        cout<<secondis[n-1]<<endl;
    }
    return 0;
}
