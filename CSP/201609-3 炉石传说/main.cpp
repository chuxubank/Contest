#include <bits/stdc++.h>
using namespace std;
struct Summon {
    int a;
    int h;
};
struct Player {
    vector<Summon> sums;
} p[2];
int main()
{
    int n;
    cin >> n;
    int player = 0;
    struct Summon Hero;
    Hero.a = 0;
    Hero.h = 30;
    p[0].sums.push_back(Hero);
    p[1].sums.push_back(Hero);
    int winner = -1;
    for (int i = 0; i < n; i++)
    {
        string in;
        cin >> in;
        if (in == "summon")
        {
            struct Summon temp_summon;
            int pos;
            cin >> pos;
            cin >> temp_summon.a;
            cin >> temp_summon.h;
            p[player].sums.insert(p[player].sums.begin() + pos, temp_summon);
        }
        else if (in == "attack")
        {
            int s1, s2;
            cin >> s1 >> s2;
            p[player].sums[s1].h -= p[(player + 1) % 2].sums[s2].a;
            p[(player + 1) % 2].sums[s2].h -= p[player].sums[s1].a;
            if (p[player].sums[s1].h <= 0)
                p[player].sums.erase(p[player].sums.begin() + s1);
            if (p[(player + 1) % 2].sums[s2].h <= 0)
            {
                if (s2 == 0)
                {
                    winner = player;
                    break;
                }
                else
                    p[(player + 1) % 2].sums.erase(p[(player + 1) % 2].sums.begin() + s2);
            }
        }
        else if (in == "end")
        {
            player = (player + 1) % 2;
        }
    }
    if (winner == 0)
        cout << 1;
    else if (winner == 1)
        cout << -1;
    else
        cout << 0;
    cout << endl;
    cout << p[0].sums[0].h << endl;
    cout << p[0].sums.size() - 1 << " ";
    for (int i = 1; i < p[0].sums.size(); i++)
        cout << p[0].sums[i].h << " ";
    cout << endl;
    cout << p[1].sums[0].h << endl;
    cout << p[1].sums.size() - 1 << " ";
    for (int i = 1; i < p[1].sums.size(); i++)
        cout << p[1].sums[i].h << " ";
    return 0;
}
