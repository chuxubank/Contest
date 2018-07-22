#include <bits/stdc++.h>
using namespace std;

int n, s;
int h[105], m[105];

int main()
{
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &h[i], &m[i]);
	}
	int fm = 0, fh = 0;
	bool flag = false;
	for(int i = 1; i < n; i++)
	{
		int dtime = (h[i] - h[i - 1]) * 60 + (m[i] - m[i - 1]);
		if(dtime >= (s * 2 + 2))
		{
			flag = true;
			fm = m[i - 1] + s + 1;
			fh = h[i - 1];
			while(fm >= 60)
			{
				fm -= 60;
				fh += 1;
			}
			break;
		}
	}
	if(flag == false)
	{
		fm = m[n - 1] + s + 1;
		fh = h[n - 1];
		while(fm >= 60)
		{
			fm -= 60;
			fh += 1;
		}
	}
	if(s <= (h[0] * 60 + m[0] - 1))
	{
		fm = 0;
		fh = 0;
	}
	printf("%d %d", fh, fm);
	return 0;
}