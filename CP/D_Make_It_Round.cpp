/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 18-11-2022 21:03:20
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
  int n1 = n, tw = 0, fi = 0;
  while (n1 % 10 == 0)
    n1 /= 10;
  int n2 = n1;
  while (n2 % 2 == 0) {
    n2 /= 2;
    tw++;
  }
  while (n1 % 5 == 0) {
    n1 /= 5;
    fi++;
  }
  debug(fi, tw);
  if (fi + tw == 0) {
    int x = 0;
    int m1 = m;
    while (m1 / 10) {
      m1 /= 10;
      x++;
    }
    cout << n * m1 * pow(10, x);
    return;
  }
  int t = 1;
  if (fi) {
    while (fi--) {
      t *= 2;
      if (t >= m)
        break;
    }
    if (t >= m)
      t /= 2;
  }
  if (tw) {
    while (tw--) {
      t *= 5;
      if (t >= m)
        break;
    }
    if (t >= m)
      t /= 5;
  }
  debug(t);
  while (t <= m)
    t *= 10;
  debug(t);
  t /= 10;
  debug(t);
  int x = m / t;
  if (x)
    cout << x * t * n;
  else
    cout << t * n;
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
