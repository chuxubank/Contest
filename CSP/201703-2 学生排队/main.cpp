#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++)
		a.push_back(i+1);
	cin>>m;
	for(int i=0; i<m; i++)
	{
		int p,q;
		cin>>p>>q;
		vector<int>::iterator pos;
		pos=find(a.begin(),a.end(),p);
		a.erase(pos);
		a.insert(pos+q,p);
	}
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}
//迭代器的使用