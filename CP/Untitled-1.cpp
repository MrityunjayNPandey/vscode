/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-09-2021 16:24:12
 **/
// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; 
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;

// clang-format on
#define int long long

int k = 0, n = 0;

int checkRecord(int n, int i = 0, int ab = 0, int prev = 0) {
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(2, vector<int>(3, 0)));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      dp[0][i][j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        int ab = 0, p = 0, l = 0;
        p += dp[i - 1][j][k];
        if (j >= 1)
          ab = dp[i - 1][j - 1][k];
        if (k >= 1)
          l = dp[i - 1][j][k - 1];
        (dp[i][j][k] = p + ab + l)%=MOD;
      }
    }
  }
  return dp[n][1][2];
}

void solve() {
  int n;
  cin >> n;
  cout << checkRecord(n);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      int Test = 1;
  // cin >> Test;
  for (int I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}