/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 17-12-2022 22:08:51
 **/
// clang-format off
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 73;
#define dclear(x) 73;
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<vector<int>> vv(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vv[i][j];
      if (vv[i][j] == 1)
        cnt++;
    }
  }
  int equal = cnt / n;
  debug(vv);
  if (cnt % n) {
    cout << -1 << endl;
    return;
  }
  map<int, set<int>> extra, less;
  for (int i = 0; i < n; i++) {
    if (count(all(vv[i]), 1) < equal) {
      for (int j = 0; j < m; j++) {
        if (vv[i][j] == 0) {
          less[i].insert(j);
        }
      }
    }
    if (count(all(vv[i]), 1) > equal) {
      for (int j = 0; j < m; j++) {
        if (vv[i][j] == 1) {
          extra[i].insert(j);
        }
      }
    }
  }
  debug(less, extra, equal);
  vector<tuple<int, int, int>> vt;
  while (extra.size()) {
    pair<int, set<int>> pi = *(extra.begin());
    int li = pi.first;
    vector<int> temp;
    for (auto &[lj, rj] : less) {
      if (extra[li].size() == equal)
        break;
      vector<int> temp0;
      cnt = extra[li].size();
      for (auto k : extra[li]) {
        debug(lj, rj.size());
        if (rj.find(k) != rj.end()) {
          vt.pb({li, lj, k});
          rj.erase(k);
          temp0.pb(k);
          cnt--;
        }
        debug(lj, rj.size());
        if (rj.size() == m - equal) {
          temp.pb(lj);
          break;
        }
        if (cnt == equal) {
          break;
        }
      }
      for (auto it : temp0) {
        extra[li].erase(it);
      }
    }
    for (auto i : temp) {
      less.erase(i);
    }
    if (extra[li].size() > equal) {
      cout << -1 << endl;
      return;
    }
    extra.erase(extra.begin());
  }
  debug(extra, less);
  cout << vt.size() << endl;
  for (auto [p, q, r] : vt) {
    cout << p + 1 << " " << q + 1 << " " << r + 1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}