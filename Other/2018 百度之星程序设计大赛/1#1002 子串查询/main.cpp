#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int T, n, q, l, r, ca = 0;
int a[26];
int map[maxn][maxn];

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> q;
		string s;
		cin >> s;
		cout << "Case #" << ++ca << ":" << endl;
		while(q--)
		{
			memset(a, 0, sizeof a);
			cin >> l >> r;
			string sb_s = s.substr(l - 1, r - l + 1);
			for(int i = 0; i < sb_s.length(); i++)
			{
				a[sb_s[i] - 'A']++;
			}
			for(int i = 0; i < 26; i++)
			{
				if(a[i] != 0)
				{
					cout << a[i] << endl;
					break;
				}
			}
		}
	}
	return 0;
}