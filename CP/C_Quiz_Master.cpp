/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 09-02-2023 16:21:52
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
  int n = 0, m = 0, k = 0, ans = INF, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<int> v(n), vans, vfact;
  set<int> fact, st1;
  for (auto &i : v)
    cin >> i;
  sort(all(v));
  debug(v) vector<vector<int>> vv(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j * j <= v[i]; j++) {
      if (v[i] % j == 0) {
        vv[i].pb(j);
        if (j != v[i] / j)
          vv[i].pb(v[i] / j);
      }
    }
  }
  int l = 0, r = 0;
  while (l < n && r <= n) {
    if (mp.size() < m) {
      if (r == n) {
        break;
      }
      for (auto i : vv[r]) {
        if (i <= m) {
          mp[i]++;
        }
      }
      r++;
    } else {
      ans = min(ans, v[r - 1] - v[l]);
      for (auto i : vv[l]) {
        if (mp.count(i)) {
          mp[i]--;
          if (mp[i] == 0)
            mp.erase(i);
        }
      }
      l++;
    }
  }
  if (ans == INF) {
    cout << -1;
    return;
  }
  cout << ans;
  debug(vv)
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
    cout << endl;
  }
}