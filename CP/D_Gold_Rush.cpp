/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-05-2023 20:55:26
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
  if (n < m) {
    cout << "NO";
    return;
  }
  if (m & 1) {
    while (n) {
      if (n == m) {
        cout << "YES";
        return;
      }
      if (n % 3)
        break;
      n /= 3;
    }
    cout << "NO";
    return;
  }
  int x = 0;
  int n1 = n;
  while (n1) {
    if (n1 & 1)
      break;
    else {
      cnt++;
      n1 /= 2;
    }
  }
  int m1 = m, cnt1 = 0;
  while (m1) {
    if (m1 & 1) {
      break;
    } else {
      cnt1++;
      m1 /= 2;
    }
  }
  debug(cnt, cnt1);
  if (cnt > cnt1) {
    cout << "NO";
    return;
  }
  int y = cnt1 - cnt;
  cnt = 0;
  while (y--) {
    m /= 2;
    m *= 3;
  }
  while (n) {
    if (n == m) {
      cout << "YES";
      return;
    }
    if (n % 3)
      break;
    n /= 3;
  }
  cout << "NO";
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
