/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 28-09-2022 19:32:19
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
// clang-format on
#define int long long

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int x, y, st = 0;
  cin >> n >> x >> y;
  string str1, str2;
  cin >> str1 >> str2;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      v.pb(1);
      if (k == 0)
        st = i;
      k++;
    } else
      v.pb(0);
  }
  if (k % 2 == 1) {
    cout << -1;
    return;
  } else {
    if (k == 2) {
      if (st != n - 1) {
        if (v[st] == v[st + 1]) {
          cout << min(x, 2 * y);
        } else
          cout << y;
        return;
      }
      if (st != 0) {
        if (v[st] == v[st - 1]) {
          cout << min(x, 2 * y);
        } else
          cout << y;
        return;
      }
    } else {
      cout << k * y / 2;
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
    cout << endl;
  }
}