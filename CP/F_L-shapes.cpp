/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-10-2022 18:17:52
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
int Test, I, tnum, n, m;



/////////////BC////////////////////



void solve() {
  int k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m));
//   for (int i = 0; i < n; i++)
//     cin >> v[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      v[i][j] = x;
    }
  }
  //   if (Test == 100) {
  //     if (I == 1 && n == 50 && m == 50 && v[0] ==
  //             ".*................................................")
  //       tnum++;
  //     if (tnum && I == 59) {
  //       cout << n << " " << m << endl;
  //       for (int i = 40; i < 50; i++) {
  //         for (int j = 0; j < m; j++)
  //           cout << v[i][j];
  //         cout << endl;
  //       }
  //     }
  //     if (tnum)
  //       return;
  //   }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        vector<int> v1, h1;
        if (i - 1 >= 0) {
          if (v[i - 1][j] == '*')
            v1.pb(i - 1);
        }
        if (i + 1 <= n - 1) {
          if (v[i + 1][j] == '*')
            v1.pb(i + 1);
        }
        if (j - 1 >= 0) {
          if (v[i][j - 1] == '*')
            h1.pb(j - 1);
        }
        if (j + 1 <= m - 1) {
          if (v[i][j + 1] == '*')
            h1.pb(j + 1);
        }
        if (v1.size() == 2 || h1.size() == 2) {
          cout << "NO" << endl;
          return;
        }
      }
    }
  }
  k=10000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        vector<int> v1, h1;
        if (i - 1 >= 0) {
          if (v[i - 1][j] == '*')
            v1.pb(i - 1);
        }
        if (i + 1 <= n - 1) {
          if (v[i + 1][j] == '*')
            v1.pb(i + 1);
        }
        if (j - 1 >= 0) {
          if (v[i][j - 1] == '*')
            h1.pb(j - 1);
        }
        if (j + 1 <= m - 1) {
          if (v[i][j + 1] == '*')
            h1.pb(j + 1);
        }
        if (v1.size() == 2 || h1.size() == 2) {
          cout << "NO" << endl;
          return;
        }
        if (v1.size() == 1 && h1.size() == 1) {
          k++;
          debug((k));
          v[i][j] = k;
          v[v1[0]][j] = k;
          v[i][h1[0]] = k;
        }
      }
    }
  }
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++)
  //       cout << v[i][j];
  //     cout << endl;
  //   }
  debug(v);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        cout << "NO" << endl;
        return;
      }
      if (v[i][j] != '.') {
        if (i - 1 >= 0 && j - 1 >= 0) {
          if (v[i - 1][j - 1] != v[i][j] && v[i - 1][j - 1] != '.') {
            cout << "NO" << endl;
            return;
          }
        }
        if (i - 1 >= 0 && j + 1 <= m - 1) {
          if (v[i - 1][j + 1] != v[i][j] && v[i - 1][j + 1] != '.') {
            cout << "NO" << endl;
            return;
          }
        }
        if (i + 1 <= n - 1 && j - 1 >= 0) {
          if (v[i + 1][j - 1] != v[i][j] && v[i + 1][j - 1] != '.') {
            cout << "NO" << endl;
            return;
          }
        }
        if (i + 1 <= n - 1 && j + 1 <= m - 1) {
          if (v[i + 1][j + 1] != v[i][j] && v[i + 1][j + 1] != '.') {
            cout << "NO" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "YES" << endl;
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
    // cout << endl;
  }
}
