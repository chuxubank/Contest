#include <bits/stdc++.h>
using namespace std;

const int maxmn = 11;

int data[maxmn][maxmn];
int vis[maxmn][maxmn];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n, sum = 0, ans = INT_MAX;

void dfs(int x, int y, int csum, int ccount)
{
    if (data[x][y] > sum / 2 || csum > sum / 2 || ccount >= ans)
        return;
    if (csum == sum / 2)
    {
        ans = min(ccount, ans);
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            dfs(nx, ny, csum + data[x][y], ccount + 1);
    }
    vis[x][y] = 0;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
            sum += data[i][j];
        }
    }
    if (sum % 2)
        cout << 0 << endl;
    else
    {
        dfs(0, 0, 0, 0);
        cout << (ans == INT_MAX ? 0 : ans) << endl;
    }
    return 0;
}