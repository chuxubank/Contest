#include <bits/stdc++.h>

using namespace std;
struct Summon
{
    int a;
    int h;
};
struct Player
{
    vector<Summon> sums;
}p[2];
int main()
{
    int n;
    cin>>n;
    int player=0;
    for(int i=0;i<n;i++)
    {
        string in;
        cin>>in;
        if(in=="summon")
        {
            struct Summon temp_summon;
            int pos;
            cin>>pos;
            cin>>temp_summon.a;
            cin>>temp_summon.h;
            p[player].sums.insert(p[player].sums.begin()+pos,temp_summon);
        }
        else if(in=="attack")
        {

        }
        else if(in=="end")
        {
            player=(player+1)%2;
        }
    }
    return 0;
}
