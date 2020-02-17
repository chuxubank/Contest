#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  ll fac[n + 1];
  fac[0] = 1;
  for (auto i = 1; i <= n; ++i)
    fac[i] = fac[i - 1] * i % m;
  ll ans = 0;
  for (auto i = 1; i <= n; ++i)
    ans += fac[n - i + 1] * fac[i] % m * (n - i + 1) % m;
  ans %= m;
  cout << ans << endl;
  return 0;
}
