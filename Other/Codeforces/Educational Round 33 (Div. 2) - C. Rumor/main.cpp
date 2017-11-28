#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
ll c[maxn],min_cost,ans=0;
int n,m;
bool vis[maxn];
// vector<int> conn[maxn];
vector< vector<int> > conn;

void dfs(int ch)
{
    if(vis[ch])
        return;
    min_cost=min(c[ch],min_cost);
    vis[ch]=true;
    for(auto& i : conn[ch])
        dfs(i);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    conn.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            min_cost=c[i];
            dfs(i);
            ans+=min_cost;
        }
    }
    cout<<ans<<endl;
    return 0;
}

// 并查集
// #include <bits/stdc++.h>
// using namespace std;
// int p[100005], a[100005], cnt[100005];
// int findset(int x){
//     return p[x] == x ? x : p[x] = findset(p[x]);
// }
// int main(){
//     int n, m;
//     cin >> n >> m;
//     for(int i = 1; i <= n; ++i){
//         p[i] = i;
//     }
//     for(int i = 1; i <= n; ++i){
//         scanf("%d", &a[i]);
//     }
//     int x, y;
//     for(int i = 1; i <= m; ++i){
//         scanf("%d %d", &x, &y);
//         p[findset(x)] = findset(y); //合并
//     }
//     long long ans = 0;
//     memset(cnt, 0, sizeof(cnt));
//     for(int i = 1; i <= n; ++i){
//         if(findset(i) == i){
//             cnt[i] = 1e9;
//         }
//     }
//     for(int i = 1; i <= n; ++i){
//         cnt[findset(i)] = min(cnt[findset(i)], a[i]);
//     }
//     for(int i = 1; i <= n; ++i){
//         if(findset(i) == i){
//             ans += cnt[i];
//         }
//     }
//     cout<<ans<<endl;
// }

// 大佬的写法
// #include <bits/stdc++.h>
//
// #define inf 2000000000
// using namespace std;
//
// typedef long long ll;
//
// int c[100005];
// vector<int> g[100005];
//
// int dfs(int i){
//     if(c[i] < 0)
//         return inf;
//
//     int ans = c[i];
//     c[i] = -1;
//
//     for(int j=0;j<g[i].size();j++)
//         ans = min(ans, dfs(g[i][j]));
//
//     return ans;
// }
//
// main(){
//     int n, m;
//     scanf("%d %d", &n, &m);
//
//     for(int i=0;i<n;i++)
//         scanf("%d", &c[i]);
//     for(int i=0;i<m;i++){
//         int a, b;
//         scanf("%d %d", &a, &b);
//         a--;
//         b--;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }
//
//     ll ans = 0LL;
//     for(int i=0;i<n;i++)
//         if(c[i] >= 0)
//             ans += dfs(i);
//     printf("%lld\n", ans);
// }

// 利用vector当作邻接表存储 dfs遍历并更新最小值
// 注意vector嵌套的用法 和resize
