#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int p, q, r, i;
	int a[4];
	while(scanf("%d%d%d", &p, &q, &r) != EOF)
	{
		int maxv = max(p, max(q, r));
		//int minv=min(p,min(q,r));
		if(p == maxv)
		{
			a[1] = 3;
			a[2] = 1;
			a[3] = 2;
		}
		else if(q == maxv)
		{
			a[1] = 1;
			a[2] = 2;
			a[3] = 3;
		}
		else
		{
			a[1] = 2;
			a[2] = 3;
			a[3] = 1;
		}
		for(i = 1; i <= 33; i++)
		{
			cout << a[1] << endl;
			cout << a[2] << endl;
			cout << a[3] << endl;
		}
		cout << a[1] << endl;
	}
	return 0;
}