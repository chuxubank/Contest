#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
#define ll long long
ll n,m,k,ans=0;
int a[30][30],num=0;
//f_zyj的快速幂模板有误
ll powM(ll x,ll n,ll mod)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
bool judger(int p)
{
    bool flag=true;
    int r=1;
    for(int j=0;j<m;j++)
        r*=a[p][j];
    if(r!=k)
        flag=false;
    return flag;
}

bool judgec(int q)
{
    bool flag=true;
    int c=1;
    for(int i=0;i<n;i++)
        c*=a[i][q];
    if(c!=k)
        flag=false;
    return flag;
}

void dfs(int p,int q)
{
    if(p==n && q==0)
    {
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(judger(i)==false)
                flag=false;
        }
        for(int j=0;j<m;j++)
        {
            if(judgec((j)==false))
                flag=false;
        }
        if(flag==true)
        {
//            for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<m;j++)
//                {
//                    cout<<a[i][j]<<" ";
//                }
//                cout<<endl;
//            }
//            cout<<endl;
            ans++;
        }
        return;
    }
    //剪枝
    if(q==0 && p>0 && judger(p-1)==false)
        return;
    if(p==n && judgec(q)==false)
        return;

    a[p][q]=1;
    if(q+1==m)
        dfs(p+1,0);
    else
        dfs(p,q+1);
    a[p][q]=-1;
    if(q+1==m)
        dfs(p+1,0);
    else
        dfs(p,q+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    //测量时间
    clock_t start_time=clock();
    {
        if((n-m)%2!=0 && k==-1)
        ans=0;
        else
            ans=powM(powM(2,n-1,mod),m-1,mod);
//            dfs(0,0);
        cout<<ans<<endl;
    }
    clock_t end_time=clock();
    cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;//输出运行时间
    return 0;
}
