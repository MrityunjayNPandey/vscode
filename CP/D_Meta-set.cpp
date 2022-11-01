/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-10-2022 12:07:51
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
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  int p = n;
  vector<vector<int>> vv;
  map<vector<int>, int> mp, mp1;
  while (p--) {
    vector<int> v(k);
    for (int i = 0; i < k; i++)
      cin >> v[i];
    mp[v]++;
    vv.pb(v);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> match;
      for (int temp = 0; temp < k; temp++) {
        if (vv[i][temp] == vv[j][temp]) {
          match.pb(vv[j][temp]);
        } else {
          if (0 != vv[i][temp] && 0 != vv[j][temp])
            match.pb(0);
          if (1 != vv[i][temp] && 1 != vv[j][temp])
            match.pb(1);
          if (2 != vv[i][temp] && 2 != vv[j][temp])
            match.pb(2);
        }
      }
      if (mp.count(match)) {
        mp1[match]++;
      }
    }
  }
  debug(mp1);
  for (auto i : mp1) {
    ans += i.second * (i.second - 1) / 2;
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  // cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
