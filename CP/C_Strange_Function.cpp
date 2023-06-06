/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-06-2023 03:55:15
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

// O(log(n)), representing powers in binary form.
int bin_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      (res *= a) %= MOD;
    }
    p >>= 1;
    (a *= a) %= MOD;
  }
  return res;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  int mult = 1;
  k = 1;
  (ans += n / mult) %= MOD;
  while (mult <= n) {
    (ans += n / mult) %= MOD;
    k++;
    map<int, int> fact, fact1;
    int mult1 = mult;
    for (int i = 2; i * i <= mult1; i++) {
      while (mult1 % i == 0) {
        fact[i]++;
        mult1 /= i;
      }
    }
    if (mult1 > 1) {
      fact[mult1]++;
    }
    int k1 = k;
    for (int i = 2; i * i <= k1; i++) {
      while (k1 % i == 0) {
        fact1[i]++;
        k1 /= i;
      }
    }
    if (k1 > 1) {
      fact1[k1]++;
    }
    for (auto &[l, r] : fact1) {
      mult *= bin_pow(l, max(0LL, r - fact[l]));
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
