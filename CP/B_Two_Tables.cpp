/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 15-11-2022 16:12:48
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int hr, wr;
  cin >> wr >> hr;
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int wf, hf;
  cin >> wf >> hf;
  int wp = x2 - x1, hp = y2 - y1;
  debug(wp, hp);
  if ((wr - wp) >= wf || (hr - hp) >= hf) {
    int x = max(x1, wr - x2);
    int y = max(y1, hr - y2);
    debug(x1, wr - x2, y1, hr - y2);
    if (x >= wf || y >= hf) {
      cout << 0 << endl;
    } else {
      debug(wf - x, hf - y);
      if (wr == 1) {
        cout << hf - y << endl;
      } else if (hr == 1) {
        cout << wf - x << endl;
      } else {
        if (wr - wp >= wf && hr - hp >= hf) {
          cout << min(wf - x, hf - y) << endl;
        } else if (wr - wp >= wf) {
          cout << wf - x << endl;
        } else
          cout << hf - y << endl;
      }
    }
  } else
    cout << -1 << endl;
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
  }
}
