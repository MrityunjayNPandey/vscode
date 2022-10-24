/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 24-10-2022 16:36:18
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, p;
  cin >> n >> p;
  vector<int> v(n + 1), psum(n + 1), pxor(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  int l, r;
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + v[i];
    pxor[i] = pxor[i - 1] ^ v[i];
  }
  debug(psum, pxor);
  auto query = [&](int b, int a) {
    int val = psum[a] - psum[b - 1] - (pxor[a] ^ pxor[b - 1]);
    return val;
  };
  while (p--) {
    cin >> l >> r;
    int size = r - l + 1;
    int right = r;
    for (int i = r; i >= l; i--) {
      int lb = l, ub = i;
      ans = -1e9;
      while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (query(mid, i) == query(l, r)) {
          ans = mid;
          lb = mid + 1;
        } else
          ub = mid - 1;
      }
      int curr = i - ans + 1;
      if (curr < size) {
        size = curr;
        right = i;
      }
    }
    cout << right - size + 1 << " " << right<<endl;
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
    // cout << endl;
  }
}
