/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-10-2022 00:29:16
 **/
// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  if (n == 1) {
    cout << 0 << endl;
    return;
  } else {
    vector<pair<int, int>> vp;
    if (v[0] != v[n - 1]) {
      vp.pb({0, n - 1});
    }
    if ((v[0] + v[n - 1]) % 2 == 0)
      v[0] = v[n - 1];
    else
      v[n - 1] = v[0];
    for (int i = 1; i < n - 1; i++) {
      if ((v[i] + v[0]) % 2 == 0)
        vp.pb({i, n - 1});
      else
        vp.pb({0, i});
    }
    cout << vp.size() << endl;
    for (int i = 0; i < vp.size(); i++) {
      cout << vp[i].first + 1 << " " << vp[i].second + 1 << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      int Test = 1;
  cin >> Test;
  for (int I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    // cout << endl;
  }
}
