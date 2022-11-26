/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-11-2022 15:02:58
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
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
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> vv[i][j];
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mp[i + j].pb(vv[i][j]);
    }
  }
  debug(mp)
  for (auto [l, r] : mp) {
    vector<int> vt;
    for (int i = 0; i < r.size(); i++) {
      vt.pb(r[i]);
    }
    if (m + n - 2 - l <= l)
      break;
    auto p = mp[m + n - 2 - l];
    for (int i = 0; i < p.size(); i++) {
      vt.pb(p[i]);
    }
    debug(vt);
    int on = 0, ze = 0;
    for (int i = 0; i < vt.size(); i++) {
      if (vt[i] == 0)
        ze++;
      else
        on++;
    }
    ans += min(on, ze);
  }
  cout << ans;
  //  chutiyapp function that does chutiyappa so, it is just for show
  //   function<int(int, int)> func = [&](int i, int j) {
  //     v.pb(vv[i][j]);
  //     debug(i, j, v);
  //     int rt = 0, dn = 0;
  //     if (i == n - 1 || j == m - 1) {
  //       if (i == n - 1 && j == m - 1) {
  //         debug(v);
  //         int ret = 0;
  //         for (int k = 0; k < v.size() / 2; k++) {
  //           if (v[k] != v[v.size() - k - 1]) {
  //             ret++;
  //           }
  //         }
  //         v.pop_back();
  //         debug(ret);
  //         return ret;
  //       } else {
  //         if (i != n - 1) {
  //           rt = func(i + 1, j);
  //         } else {
  //           dn = func(i, j + 1);
  //         }
  //       }
  //     } else {
  //       rt = func(i + 1, j);
  //       dn = func(i, j + 1);
  //     }
  //     v.pop_back();
  //     return rt + dn;
  //   };
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
