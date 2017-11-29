#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] < a[i])
                left++;
            else if (a[j] > a[i])
                right++;
        }
        if (left == right)
        {
            ans = a[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
