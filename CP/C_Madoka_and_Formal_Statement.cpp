/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-10-2022 18:18:11
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
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n), v1(n);
  int ind, mx = -INF;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (mx <= v[i]) {
      ind = i;
      mx = v[i];
    }
  }
  for (int i = 0; i < n; i++)
    cin >> v1[i];
  //   if (Test == 40000) {
  //     if (I == 5603) {
  //       cout << n << endl;
  //       for (auto i : v)
  //         cout << i << " ";
  //       cout << endl;
  //       for (auto i : v1)
  //         cout << i << " ";
  //     }
  //     return;
  //   }
  for (int i = 0; i < n; i++) {
    if (v[i] > v1[i]) {
      cout << "NO" ;
      return;
    }
    if (v[i] == v1[i])
      k++;
  }
  if (k == n) {
    cout << "YES" ;
    return;
  }
  //   for (int i = ind - 1; i >= 0; i--) {
  //     if (min(v1[i], v[i + 1] + 1) >= v[i])
  //       v[i] = min(v1[i], v[i + 1] + 1);
  //   }
  //   debug(v);
  //   if (v1[n - 1] > v[0] + 1 && v[n - 1] != v1[n - 1]) {
  //     cout << "NO" << endl;
  //     return;
  //   } else
  //     v[n - 1] = v1[n - 1];
  //   debug(v);
  //   for (int i = n - 2; i >= 0; i--) {
  //     if (v[i] == v1[i]) {
  //       debug(i);
  //       continue;
  //     }
  //     if (v1[i] > v[i + 1] + 1) {
  //       debug(i) cout << "NO" << endl;
  //       return;
  //     } else {
  //       v[i] = v1[i];
  //     }
  //   }
  //   debug(v);
  //   cout << "YES" << endl;
  for (int i = 0; i < n - 1; i++) {
    if (!(v[i] == v1[i] || v1[i] <= v1[i + 1] + 1)) {
      cout << "NO";
      return;
    }
  }
  if (!(v[n - 1] == v1[n - 1] || v1[n - 1] <= v1[0] + 1)) {
    cout << "NO";
    return;
  }
  cout << "YES";
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
