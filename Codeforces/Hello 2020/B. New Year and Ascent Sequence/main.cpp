#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l;
  vector<pi> pr;
  cin >> n;
  int64_t ans = (int64_t)n * n;
  for (int i = 0; i < n; i++) {
    cin >> l;
    vector<int> v(l);
    for (int i = 0; i < l; i++) {
      cin >> v[i];
    }
    reverse(v.begin(), v.end());
    if (is_sorted(v.begin(), v.end()))
      pr.emplace_back(v[0], v.back());
  }
  sort(pr.begin(), pr.end());
  for (int i = 0; i < pr.size(); i++) {
    ans -= pr.end() - lower_bound(pr.begin(), pr.end(), pi(pr[i].second, -1));
  }
  cout << ans << endl;
  return 0;
}
