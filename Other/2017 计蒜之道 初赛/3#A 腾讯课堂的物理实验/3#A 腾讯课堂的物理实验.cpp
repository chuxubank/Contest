#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int l,t,T,d;
	cin>>l>>t>>T;
	int a=T;
	int b=T-t;
	int tmpa=a%l;
	if(((a/l)&1)==0)
		a=tmpa;
	else
		b=l-tmpb;
	int tmpb=b%l;
	if(((b/l)&1)==0)
		b=tmpb;
	else
		b=l-tmpb;
	cout<<abs(a-b);
	return 0;
}
