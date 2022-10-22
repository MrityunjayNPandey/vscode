/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 22-10-2022 21:31:51
 **/
// clang-format off
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<pair<int, int>> vp;
  int st = 0, en = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1' && !k)
      st = i, k++;
    if (str[i] == '0' && k) {
      en = i - 1;
      vp.pb({st, en});
      k = 0;
    }
  }
  if (k)
    vp.pb({st, n - 1});
  debug(vp) for (auto i : vp) {
    if (i.first == 0) {
      for (int j = i.first; j <= i.second; j++)
        ans += v[j];
    } else {
      int mi = INF;
      for (int j = i.first - 1; j <= i.second; j++) {
        ans += v[j];
        mi = min(mi, v[j]);
      }
      ans -= mi;
    }
  }
  cout << ans;
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
