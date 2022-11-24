/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 21-11-2022 21:31:12
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
  int c, d;
  cin >> n >> c >> d;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  sort(rall(v));
  if (v[0] * d < c) {
    cout << "Impossible";
    return;
  }
  for (int i = 0; i < min(n, d); i++)
    sum += v[i];
  if (sum >= c) {
    cout << "Infinity";
    return;
  }
  int l = 0, r = d;
  while (l <= r) {
    int mid = (l + r) / 2;
    sum = (1 + (d - 1) / (mid + 1)) * v[0];
    for (int i = 0; i < min(mid, n - 1); i++) {
      sum += (1 + (d - 2 - i) / (mid + 1)) * v[i + 1];
    }
    if (sum >= c) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
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
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
