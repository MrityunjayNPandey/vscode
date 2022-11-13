/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-10-2022 17:01:38
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
#define debug(...) 73
#define print(x) 73
#define dclear(x) 73
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
  cin >> n;
  int x1, y1, x2, y2, x3, y3, r1, r2;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cin >> r1 >> r2;
  if (x1 != x2 && y1 != y2) {
    if (x3 == 1 && y3 == 1 || x3 == 1 && y3 == n || x3 == n && y3 == n ||
        x3 == n && y3 == 1) {
      if (r1 == x3 || r2 == y3) {
        cout << "YES";
      } else
        cout << "NO";
    } else if (x3 % 2 == r1 % 2 || y3 % 2 == r2 % 2)
      cout << "YES";
    else
      cout << "NO";
  } else if (x1 != x3 && y1 != y3) {
    if (x2 == 1 && y2 == 1 || x2 == 1 && y2 == n || x2 == n && y2 == n ||
        x2 == n && y2 == 1) {
      if (r1 == x2 || r2 == y2) {
        cout << "YES";
      } else
        cout << "NO";
    } else if (x2 % 2 == r1 % 2 || y2 % 2 == r2 % 2)
      cout << "YES";
    else
      cout << "NO";
  } else if (x2 != x3 && y2 != y3) {
    if (x1 == 1 && y1 == 1 || x1 == 1 && y1 == n || x1 == n && y1 == n ||
        x1 == n && y1 == 1) {
      if (r1 == x1 || r2 == y1) {
        cout << "YES";
      } else
        cout << "NO";
    } else if (x1 % 2 == r1 % 2 || y1 % 2 == r2 % 2)
      cout << "YES";
    else
      cout << "NO";
  }
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
