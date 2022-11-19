/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-11-2022 16:20:19
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
  int q;
  cin >> n >> q;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<vector<int>> dp(2, vector<int>(n + 1, -1));
  debug(dp);
  function<int(int, int, int)> func = [&](int prev, int ind, int flag) {
    int choose = 0, nchoose = 0;
    debug(prev, ind, flag);
    if (dp[flag][prev] != -1) {
      return dp[flag][prev];
    }
    if (ind < n) {
      if (flag == 0) {
        choose = func(v[ind], ind + 1, 1) + v[ind];
        nchoose = func(prev, ind + 1, 0);
      } else {
        if (v[ind] < prev) {
          choose = func(v[ind], ind + 1, 0) - v[ind];
        }
        nchoose = func(prev, ind + 1, 1);
      }
    }
    return dp[flag][prev] = max(choose, nchoose);
  };
  //Tabultion
  dp[0][0] = v[0];
  dp[1][0] = 0;
  for (int i = 1; i < n; i++) {
    dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + v[i]);
    dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - v[i]);
  }
  cout << max(dp[0][n - 1], dp[1][n - 1]);
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
