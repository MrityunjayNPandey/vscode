/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-10-2022 21:22:25
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
int Test, I, tnum;

void solve() {
  int n;
  cin >> n;

  vector<int> x(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    x[i] *= 2;
  }

  for (int i = 0; i < n; i++) {
    cin >> t[i];
    t[i] *= 2;
  }
 debug(x, t)
  int l = -1, r = INF;
  while (r - l > 1) {
    int m = (l + r) / 2;

    int mxl = 0, mnr = INF;
    for (int i = 0; i < n; i++) {
      if (t[i] > m) {
        mxl = INF;
        mnr = 0;
        break;
      } else {
        mxl = max(mxl, x[i] - (m - t[i]));
        mnr = min(mnr, x[i] + (m - t[i]));
      }
    }

    if (mxl <= mnr)
      r = m;
    else
      l = m;
  }

  int mxl = 0, mnr = INF;
  for (int i = 0; i < n; i++) {
    mxl = max(mxl, x[i] - (r - t[i]));
    mnr = min(mnr, x[i] + (r - t[i]));
  }

  cout << mxl / 2;
  if (mxl % 2 != 0)
    cout << ".5";
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
