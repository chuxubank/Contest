#include <bits/stdc++.h>
using namespace std;

int n;
float a0, al, c[1001];

float geta(int i)
{
	if(i == 0)
		return a0;
	if(i == n + 1)
		return al;
	return (geta(i - 1) + geta(i + 1)) / 2 - c[i];
}

int main()
{
	cin >> n;
	cin >> a0 >> al;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	printf("%.2f", geta(1));
	return 0;
}