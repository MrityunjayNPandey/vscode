/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-11-2022 13:35:12
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
  vector<vector<int>> vv(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vv[i][j];
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m / 2; j++) {
      vector<int> v(4);
      int a = vv[i][j];
      int b = vv[i][m - j - 1];
      int c = vv[n - i - 1][j];
      int d = vv[n - i - 1][m - j - 1];
      v = {a, b, c, d};
      sort(all(v));
      int x = v[1];
      vv[i][j] = x;
      vv[i][m - j - 1] = x;
      vv[n - i - 1][j] = x;
      vv[n - i - 1][m - j - 1] = x;
      ans += abs(x - a) + abs(x - b) + abs(x - c) + abs(x - d);
    }
  }
  debug(vv);
  debug(ans);
  if (n & 1) {
    for (int j = 0; j < m / 2; j++) {
      int a = vv[n / 2][j];
      int b = vv[n / 2][m - j - 1];
      int x = (a + b) / 2;
      vv[n / 2][j] = x;
      vv[n / 2][m - j - 1] = x;
      ans += abs(x - a) + abs(x - b);
    }
  }
  debug(vv);
  if (m & 1) {
    for (int i = 0; i < n / 2; i++) {
      int a = vv[i][m / 2];
      int b = vv[n - i - 1][m / 2];
      int x = (a + b) / 2;
      vv[i][m / 2] = x;
      vv[n - i - 1][m / 2] = x;
      ans += abs(x - a) + abs(x - b);
    }
  }
  debug(vv);
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
