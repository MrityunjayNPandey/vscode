/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 07-05-2023 22:56:38
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

vector<vector<int>> vv = vector<vector<int>>(2023, vector<int>(2023, 0));
vector<vector<int>> prefix = vector<vector<int>>(2023, vector<int>(2023, 0));

vector<int> row = vector<int>(2023, 0);

void pref() {
  int k = 1;
  for (int i = 0; i < 2023; i++) {
    for (int j = 1; j <= i + 1; j++) {
      vv[i][j - 1] = k;
      k++;
    }
  }
  row[0] = 1;
  for (int i = 1; i < 2023; i++) {
    row[i] += row[i - 1] + i;
  }
  for (int i = 0; i < 2023; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        prefix[i - j][j] = vv[i][j] * vv[i][j];
        continue;
      }
      prefix[i - j][j] += prefix[i - j][j - 1] + vv[i][j] * vv[i][j];
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  int rowind = upper_bound(all(row), n) - row.begin() - 1;
  int colind = n - row[rowind];
  rowind -= colind;
  for (int i = 0; i <= rowind; i++) {
    ans += prefix[i][colind];
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  pref();
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}