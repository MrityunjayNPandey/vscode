/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 11-06-2023 03:56:36
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
  cin >> n;
  vector<int> c(n), a(n), b(n);
  for (auto &i : c)
    cin >> i;
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;  
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
  }
  debug(a, b);
  int prev = c[n - 1] - 1;
  for (int i = n - 2; i >= 1; i--) {
    ans = max(ans, prev + 2 + b[i + 1] - a[i + 1]);
    if (a[i + 1] == b[i + 1]) {
      ans = max(ans, prev + 2);
      prev = c[i] - 1;
      continue;
    }
    if (c[i] - 1 >= prev + 2 + a[i + 1] - 1 + c[i] - b[i + 1]) {
      prev = c[i] - 1;
    } else {
      prev += 2 + a[i + 1] - 1 + c[i] - b[i + 1];
    }
  }
  debug(ans, prev);
  ans = max(ans, prev + 2 + b[1] - a[1]);
  cout << ans << endl;
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
