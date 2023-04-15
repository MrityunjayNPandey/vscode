/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-04-2023 20:15:59
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
  int n1 = min(n, m);
  int m1 = max(n, m);
  vector<int> v, v1;
  for (int i = 1; i * i <= n1; i++) {
    if (n1 % i == 0) {
      if (n1 / i == i)
        v.pb(i);
      else // Otherwise print both
        v.pb(i), v.pb(n1 / i);
    }
  }
  for (int i = 1; i * i <= m1; i++) {
    if (m1 % i == 0) {
      if (m1 / i == i)
        v1.pb(i);
      else // Otherwise print both
        v1.pb(i), v1.pb(m1 / i);
    }
  }
  sort(all(v));
  sort(all(v1));
  debug(v, v1, n1, m1);
  int ansf = INF;
  for (int i = 0; i < v.size(); i++) {
    ans = 0;
    if (v[i] <= m1) {
      ans += m1 % v[i];
      ans += v[i] - 1;
      ans += m1 / v[i];
      ans += n1 / v[i];
    } else
      break;
    ansf = min(ansf, ans);
  }
  debug(ans, ansf);
  for (int i = 0; i < v1.size(); i++) {
    ans = 0;
    if (v1[i] <= n1) {
      ans += n1 % v1[i];
      ans += v1[i] - 1;
      ans += n1 / v1[i];
      ans += m1 / v1[i];
    } else
      break;
    if (ans < ansf) {
    debug(ans, v1[i])
    }
    ansf = min(ansf, ans);
  }
  debug(ansf);
  for (int i = 0; i < v.size(); i++) {
    ans = 0;
    ans += m1;
    ans += v[i] - 1;
    ans += n1 / v[i];
    ansf = min(ansf, ans);
  }
  debug(ansf);
  for (int i = 0; i < v1.size(); i++) {
    ans = 0;
    ans += n1;
    ans += v1[i] - 1;
    ans += m1 / v1[i];
    ansf = min(ansf, ans);
  }
  debug(ansf);
  cout << ansf;
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
