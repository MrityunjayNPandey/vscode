/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 10-11-2022 22:44:11
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

vector<vector<int>> nCr(1001, vector<int>(1001));

void pref() {
  int n = 1000;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        nCr[i][j] = 1;
      else
        nCr[i][j] = (nCr[i - 1][j - 1] % mod + nCr[i - 1][j] % mod) % mod;
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<vector<int>> dp(3, vector<int>(n + 1));
  dp[0][2] = 1;
  dp[1][2] = 0;
  dp[2][2] = 1;
  for (int i = 3; i <= n; i++) {
    dp[0][i] = (nCr[i - 1][i / 2] + dp[1][i - 2]) % mod;
    dp[1][i] = (nCr[i - 2][i / 2] + dp[0][i - 2]) % mod;
    dp[2][i] = dp[2][i - 2];
  }
  debug(dp) cout << dp[0][n] << " " << dp[1][n] << " " << dp[2][n];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  pref();
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
