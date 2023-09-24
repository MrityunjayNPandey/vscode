/**
 *      codeforces: _joKer_0
 *      created: 30-08-2023 21:40:54
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, temp = 0;
  cin >> n >> m;
  vector<vector<char>> vv(n, vector<char>(m, '.'));
  vector<string> vstr(n);
  for (auto &i : vstr)
    cin >> i;
  debug(vstr);
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = 0; j < m; j++) {
      if (vstr[i][j] == 'U')
        cnt++;
    }
    if (cnt % 2) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = 0; i < m; i++) {
    cnt = 0;
    for (int j = 0; j < n; j++) {
      if (vstr[j][i] == 'L')
        cnt++;
    }
    if (cnt % 2) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      if (vstr[i][j] == 'U') {
        if (temp & 1) {
          vv[i][j] = 'B';
          vv[i + 1][j] = 'W';
        } else {
          vv[i][j] = 'W';
          vv[i + 1][j] = 'B';
        }
        temp++;
      }
    }
  }
  temp = 0;
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n; j++) {
      if (vstr[j][i] == 'L') {
        if (temp & 1) {
          vv[j][i] = 'B';
          vv[j][i + 1] = 'W';
        } else {
          vv[j][i] = 'W';
          vv[j][i + 1] = 'B';
        }
        temp++;
      }
    }
  }
  for (auto &i : vv) {
    for (auto &j : i)
      cout << j;
    cout << endl;
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
