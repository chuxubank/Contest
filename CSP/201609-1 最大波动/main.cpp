#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;

int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int maxd=0;
    for(int i=1;i<n;i++)
    {
        maxd=max(maxd,(int)fabs(a[i]-a[i-1]));
    }
    cout<<maxd;
    return 0;
}
