#include<iostream>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	while(n>=50)
	{
		n-=50;
		ans+=7;
	}
	while(n>=30)
	{
		n-=30;
		ans+=4;
	}
	while(n>=10)
	{
		n-=10;
		ans+=1;
	}
	cout<<ans;
	return 0;
}
