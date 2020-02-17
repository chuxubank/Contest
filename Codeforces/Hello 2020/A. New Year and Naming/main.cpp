#include <iostream>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m;
  string str1[n], str2[m];
  for (int i = 1; i < n; i++)
    cin >> str1[i];
  cin >> str1[0];

  for (int i = 1; i < m; i++)
    cin >> str2[i];
  cin >> str2[0];

  cin >> q;
  for (int i = 0; i < q; i++) {
    int year;
    cin >> year;
    int a = year % n, b = year % m;
    cout << str1[a] << str2[b] << endl;
  }
  return 0;
}
