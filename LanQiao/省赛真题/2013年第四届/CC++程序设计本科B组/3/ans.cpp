#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(int stairleft, int step)
{
    if (stairleft < 0)
        return;
    if (stairleft == 0 && step % 2 == 0)
        ans++;
    dfs(stairleft - 1, step + 1);
    dfs(stairleft - 2, step + 1);
}

int main()
{
    dfs(39, 0);
    cout << ans << endl;
    return 0;
}

// 51167078