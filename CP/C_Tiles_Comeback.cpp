/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-07-2023 20:45:04
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
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; //find_by_order(k), order_of_key(k)
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  map<int, int> mp;
  for (auto &i : v) {
    cin >> i;
  }
  if (v[0] == v[n - 1]) {
    for (auto &i : v) {
      if (i == v[0])
        cnt++;
    }
    if (cnt >= k) {
      cout << "YES";
      return;
    }
  }
  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; i++) {
    if (v[i] == v[0])
      v1[i] += 1;
    if (i > 0)
      v1[i] += v1[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] == v[n - 1])
      v2[i] += 1;
    if (i < n - 1)
      v2[i] += v2[i + 1];
  }
  debug(v1, v2) for (int i = 0; i < n - 1; i++) {
    if (v1[i] >= k && v2[i + 1] >= k) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
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
