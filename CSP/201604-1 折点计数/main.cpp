#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;

int main()
{
	int n,a[1005],count=0;
	cin>>n;
	for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n-1;i++)
    {
        if(a[i]-a[i-1]<0 && a[i]-a[i+1]<0 || a[i]-a[i-1]>0 && a[i]-a[i+1]>0)
            count++;
    }
    cout<<count<<endl;
    return 0;
}
