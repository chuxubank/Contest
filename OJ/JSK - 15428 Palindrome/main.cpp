#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int n,m,k,t,b[maxn],cnt,mo=12345;
char op[maxn];
ll a[maxn],pre[maxn],len[maxn];
unsigned ll h1[maxn],h2[maxn],h3[maxn],h4[maxn],xp[maxn];
bool check(int len,int sta,int stb,unsigned ll *h1,unsigned ll *h2)
{
    return h1[sta]-h1[sta+len]*xp[len]==h2[stb]-h2[stb-len]*xp[len];
}
int main()
{
    int i,j;
    xp[0]=1;
    for(i=1;i<=maxn-10;i++)xp[i]=xp[i-1]*mo;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            int num=0;
            scanf("%d%s",&num,op);
            if(op[0]!=b[cnt])
            {
                b[++cnt]=op[0];
                a[cnt]=num;
                pre[cnt]=pre[cnt-1]+a[cnt];
            }
            else a[cnt]+=num,pre[cnt]+=num;
        }
        h1[cnt+1]=h2[cnt+1]=0;
        for(i=cnt;i>=1;i--)
        {
            h1[i]=h1[i+1]*mo+a[i];
            h2[i]=h2[i+1]*mo+b[i]-'a';
        }
        h3[0]=h4[0]=0;
        for(i=1;i<=cnt;i++)
        {
            h3[i]=h3[i-1]*mo+a[i];
            h4[i]=h4[i-1]*mo+b[i]-'a';
        }
        ll ret=0;
        for(i=1;i<=cnt;i++)
        {
            int l=1,r=min(i,cnt-i+1),ma;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(check(mid,i-mid+1,i+mid-1,h1,h3)&&check(mid,i-mid+1,i+mid-1,h2,h4))
                {
                    ma=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            ll now=pre[i+ma-1]-pre[i-ma];
            if(b[i+ma]==b[i-ma]&&i-ma>=1&&i+ma<=cnt)now+=2*min(a[i-ma],a[i+ma]);
            ret=max(ret,now);
        }
        printf("%lld\n",ret);
    }
    return 0;
}
