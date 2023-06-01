/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 01-06-2023 13:50:06
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  string str;
  cin >> str;
  map<int, int> x, y;
  int xd = 0, yd = 0, xmin = 0, xmax = 0, ymin = 0, ymax = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'L') {
      xd--;
      xmin = min(xmin, xd);
      if (!x.contains(xd)) {
        x[xd] = i;
      }
    } else if (str[i] == 'R') {
      xd++;
      xmax = max(xmax, xd);
      if (!x.contains(xd)) {
        x[xd] = i;
      }
    } else if (str[i] == 'U') {
      yd--;
      ymin = min(ymin, yd);
      if (!y.contains(yd)) {
        y[yd] = i;
      }
    } else {
      yd++;
      ymax = max(ymax, yd);
      if (!y.contains(yd)) {
        y[yd] = i;
      }
    }
  }
  debug(x, y);
  int left = INF, indy = 0;
  for (int i = 0; i < m; i++) {
    int mina = 0;
    if (x.contains(-(i + 1))) {
      mina = max(mina, (int)str.length() - x[-(i + 1)]);
    }
    if (x.contains(m - i)) {
      mina = max(mina, (int)str.length() - x[m - i]);
    }
    if (mina < left) {
      left = mina;
      indy = i;
    }
    if (mina == 0)
      break;
  }
  left = INF;
  int indx = 0;
  for (int i = 0; i < n; i++) {
    int mina = 0;
    if (y.contains(-(i + 1))) {
      mina = max(mina, (int)str.length() - y[-(i + 1)]);
    }
    if (y.contains(n - i)) {
      mina = max(mina, (int)str.length() - y[n - i]);
    }
    if (mina < left) {
      left = mina;
      indx = i;
    }
    if (mina == 0)
      break;
  }
  cout << indx + 1 << " " << indy + 1;
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
