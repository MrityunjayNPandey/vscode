/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 20-09-2022 00:14:59
 **/
// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)c
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
// clang-format on
#define int long long

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<string> vstr;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    vstr.pb(str);
  }
  k = INF;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (vstr[i][j] == '1')
        sum++;
    }
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++) {
      int cnt = vstr[i][j] - '0' + vstr[i][j + 1] - '0' + vstr[i + 1][j] - '0' +
                vstr[i + 1][j + 1] - '0';
      k = min(k, cnt);
    }
  if (k<=2) {
    cout << max(sum, 0LL);
  } else if (k == 3) {
    cout << max(sum - 1, 0LL);
  } else
    cout << max(sum - 2, 0LL);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      int Test = 1;
  cin >> Test;
  for (int I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
