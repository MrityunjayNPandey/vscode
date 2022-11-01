/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-10-2022 16:43:34
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int c, q;
  cin >> n >> c >> q;
  string str;
  cin >> str;
  vector<pair<int, int>> vp, vp1;
  int p = c;
  int sz = str.size();
  while (p--) {
    int l, r;
    cin >> l >> r;
    vp.pb({sz + 1, sz + r - l + 1});
    vp1.pb({l, r});
    sz += r - l + 1;
    debug(sz);
  }
  debug(vp);
  while (q--) {
    int x;
    cin >> x;
    for (int i = vp.size() - 1; i >= 0; i--) {
      if (x >= vp[i].first && vp[i].second >= x) {
        debug(x, vp[i]);
        int t = vp[i].first - vp1[i].first;
        x -= t;
        debug(x)
      }
    }
    cout << str[(x - 1) % n] << endl;
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
    // cout << endl;
  }
}
