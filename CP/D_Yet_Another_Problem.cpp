/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-11-2022 03:36:56
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
#define print(x) 73;
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
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> zero(n + 1), xorv(n + 1);
  for (int i = 0; i < n; i++) {
    if (v[i] == 0)
      zero[i + 1] += 1;
    zero[i + 1] += zero[i];
  }
  debug(zero);
  map<int, vector<int>> mp1, mp2;
  for (int i = 0; i < n; i++) {
    xorv[i + 1] = xorv[i] ^ v[i];
    if ((i + 1) % 2)
      mp1[xorv[i + 1]].pb(i + 1);
    else
      mp2[xorv[i + 1]].pb(i + 1);
  }
  debug(xorv, v, mp1, mp2);
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (zero[r] - zero[l - 1] == (r - l + 1)) {
      cout << 0 << endl;
      continue;
    }
    if ((xorv[r] ^ xorv[l - 1]) != 0)
      cout << -1 << endl;
    else {
      if ((r - l + 1) % 2 || v[l - 1] == 0 || v[r - 1] == 0)
        cout << 1 << endl;
      else {
        int ind;
        if (l % 2) {
          ind =
              lower_bound(all(mp1[xorv[l - 1]]), l) - mp1[xorv[l - 1]].begin();
          if (ind == mp1[xorv[l - 1]].size()) {
            cout << -1 << endl;
            continue;
          }
          if (mp1[xorv[l - 1]][ind] <= r)
            cout << 2 << endl;
          else
            cout << -1 << endl;
        } else {
          ind =
              lower_bound(all(mp2[xorv[l - 1]]), l) - mp2[xorv[l - 1]].begin();
          if (ind == mp2[xorv[l - 1]].size()) {
            cout << -1 << endl;
            continue;
          }
          if (mp2[xorv[l - 1]][ind] <= r)
            cout << 2 << endl;
          else
            cout << -1 << endl;
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
