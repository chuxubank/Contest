#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void f(int stairleft, int step)
{
    if (stairleft < 0)
        return;
    if (stairleft == 0 && step % 2 == 0)
        ans++;
    f(stairleft - 1, step + 1);
    f(stairleft - 2, step + 1);
}

int main()
{
    f(39, 0);
    cout << ans << endl;
    return 0;
}