/**
 *      codeforces: _joKer_0
 *      created: 26-11-2023 20:25:00
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int a, b, c;
  cin >> a >> b >> c;
  cout << 1 - (abs(b - c) % 2) << " " << 1 - (abs(a - c) % 2) << " "
       << 1 - (abs(a - b) % 2);
  //   if (b == c) {
  //     cout << "1 ";
  //   } else {
  //     if ((b + c) % 2 == 0) {
  //       if (max(b, c) - (b + c) / 2 <= a) {
  //         cout << "1 ";
  //       } else
  //         cout << "0 ";
  //     } else
  //       cout << "0 ";
  //   }
  //   if (a == c) {
  //     cout << "1 ";
  //   } else {
  //     if ((a + c) % 2 == 0) {
  //       if (max(a, c) - (a + c) / 2 <= b) {
  //         cout << "1 ";
  //       } else
  //         cout << "0 ";
  //     } else
  //       cout << "0 ";
  //   }
  //   if (a == b) {
  //     cout << "1 ";
  //   } else {
  //     if ((a + b) % 2 == 0) {
  //       if (max(a, b) - (a + b) / 2 <= c) {
  //         cout << "1 ";
  //       } else
  //         cout << "0 ";
  //     } else
  //       cout << "0 ";
  //   }
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
