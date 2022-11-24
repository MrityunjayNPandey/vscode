/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 22-11-2022 16:01:49
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
  int x, pos;
  cin >> n >> x >> pos;
  int nol = 0, nor = 0;
  auto bsearch = [&](vector<int> a, int x) {
    int left = 0;
    int right = a.size();
    while (left < right) {
      int mid = (left + right) / 2;
      if (a[mid] <= x)
        left = mid + 1, nol++;
      else
        right = mid, nor++;
    }
    if (left > 0 and a[left - 1] == x)
      return true;
    else
      return false;
  };
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    v[i] = i;
  bsearch(v, pos);
  ans = 1;
  for (int i = 1; i <= n - (nol + nor); i++)
    (ans *= i) %= MOD;
  int p = x - 1;
  debug(p);
  nol--;
  while (nol--) {
    (ans *= p) %= MOD;
    p--;
  }
  int q = n - x;
  while (nor--) {
    (ans *= q) %= MOD;
    q--;
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
  Test = 1;
  // cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
