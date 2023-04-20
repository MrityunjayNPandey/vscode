/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 20-04-2023 00:22:45
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

vector<int> fib = vector<int>(46, 0);

int check(int xl0, int yl0, int xr0, int yr0, int x, int y, int fibo) {
  if (fibo <= 0) {
    return 1;
  }
  int ans = -1;
  debug(xl0, xr0, yl0, yr0);
  if (xr0 - x >= fib[fibo]) {
    ans = max(ans, check(xl0, yl0, xr0 - fib[fibo], yr0, x, y, fibo - 1));
  } else if (x - xl0 >= fib[fibo]) {
    ans = max(ans, check(xl0 + fib[fibo], yl0, xr0, yr0, x, y, fibo - 1));
  } else if (yr0 - y >= fib[fibo]) {
    ans = max(ans, check(xl0, yl0, xr0, yr0 - fib[fibo], x, y, fibo - 1));
  } else if (y - yl0 >= fib[fibo]) {
    ans = max(ans, check(xl0, yl0 + fib[fibo], xr0, yr0, x, y, fibo - 1));
  }
  return ans;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int x, y;
  cin >> n >> x >> y;
  debug(x, y);
  if (check(1, 1, fib[n], fib[n + 1], x, y, n) == 1) {
    cout << "YES";
  } else
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
  fib[0] = 1, fib[1] = 1;
  for (int i = 2; i <= 45; i++) {
    fib[i] += fib[i - 1] + fib[i - 2];
  }
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
