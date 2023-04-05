#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, ans = 0;
  cin >> n;
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s, q;
    cin >> s >> q;
    if (q == "yes") {
      int x;
      cin >> x;
      mp[s]++;
      for (int k = 0; k < x; k++) {
        string xx;
        cin >> xx;
        mp[xx]++;
      }
    }
  }
  cout << mp.size() << endl;
}

signed main() {
  int Testcase = 1;
  cin >> Testcase;
  while (Testcase--)
    solve();
  return 0;
}