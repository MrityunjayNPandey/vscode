/**
 *      codeforces: _joKer_0
 *      created: 17-11-2023 21:53:52
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, q = 0;
  cin >> n >> q;
  vector<int> v(q);
  for (auto &i : v) {
    cin >> i;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << i + 1 << " " << i + 2 << endl;
  }
  tuple<int, int, int> prev = {1, 2, -1};
  int prevScore = n - 1;
  for (int i = 0; i < q; i++) {
    auto &[u, v1, v2] = prev;
    if (v[i] == prevScore) {
      cout << "-1 -1 -1" << endl;
      continue;
    }
    prevScore = v[i];
    v2 = 1 + v[i];
    cout << u << " " << v1 << " " << v2 << endl;
    v1 = v2;
  }
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
  }
}
