/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 13-11-2022 12:56:47
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
  int a, b, d;
  cin >> a >> b >> d;
  if ((a & 1 || b & 1) && (d & 1) == 0) {
    cout << -1;
    return;
  }
  int a1 = a, b1 = b, d1 = d;
  k = 0;
  while ((a1 & 1) == 0) {
    k++;
    a1 >>= 1;
  }
  a1 = k;
  k = 0;
  while ((b1 & 1) == 0) {
    k++;
    b1 >>= 1;
  }
  b1 = k;
  k = 0;
  while ((d1 & 1) == 0) {
    k++;
    d1 >>= 1;
  }
  d1 = k;
  k = 0;
  if (min(a1, b1) < d1) {
    cout << -1;
    return;
  }
  if (d & 1) {
    cout << (1LL << 30) - 1LL;
  } else {
    int x = 30 - d1;
    ans += (1LL << (x + 1)) - 1LL;
    cout << (ans << d1);
    debug((ans << d1) % d);
  }
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
