#include <iostream>
using namespace std;
int main()
{
	int n,k,sum=0,ans=0;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		sum+=a[i];
		if(sum>=k)
		{
			sum=0;
			ans++;
		}
	}
	if(sum<k && sum!=0)
		ans++;
	cout<<ans<<endl;
	return 0;
}
