#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9 + 7;
struct Player
{
	string name;
	double fleg, oleg;
};
bool cmp(Player a, Player b)
{
	return a.oleg < b.oleg;
}

int main()
{
	int n;
	cin >> n;
	Player temp;
	vector<Player> a,b;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp.name;
		cin >> temp.fleg;
		cin >> temp.oleg;
		a.push_back(temp);
	}
    vector<string> BestTeam;
	double ans = maxn;
	for (int i = 1; i <= n; i++)
	{
	    b.clear();
		b.insert(b.end(),a.begin(),a.end());
		b.insert(b.end(),a.begin(),a.end());
		sort(b.begin()+i+1, b.begin()+i+n, cmp);
		double tmp = b[i].fleg + b[i + 1].oleg + b[i + 2].oleg + b[i + 3].oleg;
		if (tmp < ans)
		{
			ans = tmp;
			BestTeam.clear();
			for(int j=i;j<i+4;j++)
                BestTeam.push_back(b[j].name);
		}
	}
	printf("%.2f\n", ans);
	for (int i = 0; i < 4; i++)
		cout << BestTeam[i] << endl;
	return 0;
}
