/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-11-2022 03:25:47
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

//haa mai hu gaandu

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<pair<int, int>> vp(n);
  vector<int> v(n);
  for (auto &[l, r] : vp) {
    cin >> l >> r;
  }
  for (int i = 0; i < n; i++) {
    v[i] = vp[i].first;
  }
  sort(all(v));
  debug(v);
  sort(all(vp),
       [](auto &left, auto &right) { return left.second < right.second; });
  debug(vp);
  int maxa = 0;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int idx = lower_bound(all(v), vp[i].second) - v.begin();
    debug(idx);
    maxa = idx - i;
    debug(maxa);
    if (!mp.count(maxa))
      mp[maxa] = INF;
    mp[maxa] = min(mp[maxa], v[idx - 1]);
  }
  debug(mp);
  cout << (*mp.rbegin()).second << " " << (*mp.rbegin()).first;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}