/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-05-2023 20:46:43
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
  cin >> n;
  vector<int> v(n);
  set<int> pos;
  for (auto &i : v)
    cin >> i;
  for (int i = 0; i < n / 2; i++) {
    if (v[i] != v[n - 1 - i]) {
      int X = v[i], Y = v[n - 1 - i];
      int d = abs(X - Y);
      int j = 1;
      while (j * j <= d) {
        if (d % j == 0) {
          pos.insert(j);
          if (d / j != j)
            pos.insert(d / j);
        }
        j++;
      }
      break;
    }
  }
  debug(pos);
  if (pos.empty()) {
    cout << 0;
    return;
  }
  for (int i = 0; i < n / 2; i++) {
    if (v[i] != v[n - 1 - i]) {
      set<int> st;
      for (auto j : pos) {
        if (v[i] % j != v[n - 1 - i] % j) {
          st.insert(j);
        }
      }
      for (auto j : st) {
        pos.erase(j);
      }
    }
  }
  cout << *pos.rbegin();
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
