#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n+1];
    vector<int> isplaying;
    isplaying.push_back(1);
    isplaying.push_back(2);
    int loser;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        auto result=find(isplaying.begin(),isplaying.end(),a[i]);
        if(result==isplaying.end())
        {
            flag=false;
            break;
        }
        for(auto player=isplaying.begin();player!=isplaying.end();)
        {
            if(*player!=a[i])
            {
                loser=*player;
                player=isplaying.erase(player);
            }
            else
                ++player;
        }
        isplaying.push_back(6-isplaying[0]-loser);
    }
    if(flag==false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}
