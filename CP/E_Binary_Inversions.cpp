/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 21-11-2022 20:49:42
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
  cin >> n;
  vector<int> v(n), ones(n), zeros(n);
  for (auto &i : v)
    cin >> i;
  if (v[0] == 1)
    ones[0] = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] == 1)
      ones[i]++;
    ones[i] += ones[i - 1];
  }
  if (v[n - 1] == 0)
    zeros[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] == 0)
      zeros[i]++;
    zeros[i] += zeros[i + 1];
  }
  int initans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 1)
      initans += zeros[i + 1];
  }
  debug(initans, ones, zeros);
  int mx = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 0) {
      int k = 0;
      if (i > 0)
        k = zeros[i + 1] - ones[i - 1];
      else
        k = zeros[i + 1];
      mx = max(mx, k);
    }
  }
  for (int i = 1; i < n; i++) {
    if (v[i] == 1) {
      int k = 0;
      if (i < n - 1)
        k = ones[i - 1] - zeros[i + 1];
      else
        k = ones[i - 1];
      mx = max(mx, k);
    }
  }
  debug(mx);
  cout << initans + mx;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
