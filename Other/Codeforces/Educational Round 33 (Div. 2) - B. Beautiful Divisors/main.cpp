#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e9+7;
ll beautifulnums[100];
int main()
{
    for(int i=1;i<=16;i++)
        beautifulnums[i]=((1<<i)-1)*(1<<(i-1));
    ll n;
    cin>>n;
    ll maxa=0;
    for(int i=1;i<=16;i++)
    {
        if(n%beautifulnums[i]==0)
            maxa=max(beautifulnums[i],maxa);
    }
    cout<<maxa<<endl;
    return 0;
}
