/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 31-05-2023 16:49:20
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
#define pb emplace_back
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
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<vector<int>> grid(32, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    int x = v[i] / 2;
    int ind = 32;
    while (ind--) {
      grid[ind][i] = x;
      x >>= 1;
    }
  }
  vector<int> suff(n), pref(n);
  for (int i = 0; i < n; i++) {
    int r = 31, c = i;
    while (r > 0 && c < n) {
      suff[i] += grid[r][c];
      r--, c++;
    }
  }
  pref[0] = v[0];
  for (int i = 1; i < n; i++) {
    pref[i] += pref[i - 1] + v[i];
  }
  debug(v, pref, suff);
  ans = max(ans, suff[0]);
  debug(ans);
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, pref[i] - (i + 1) * k + suff[i + 1]);
    debug(ans);
  }
  ans = max(ans, pref[n - 1] - n * k);
  debug(ans);
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
