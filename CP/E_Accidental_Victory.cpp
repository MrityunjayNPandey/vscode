/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 03-11-2022 13:58:14
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
  cin >> n;
  vector<int> v(n), v2;
  vector<pair<int, int>> v1;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i], mp[v[i]].pb(i);
    cnt = max(cnt, v[i]);
  }
  for (auto i : mp) {
    v1.pb({i.first, ((i.first) * (i.second.size()))});
    v2.pb((i.first) * (i.second.size()));
  }
  for (int i = 1; i < v1.size(); i++) {
    v1[i].second += v1[i - 1].second;
    v2[i] += v2[i - 1];
  }
  debug(v1, v2);
  vector<int> vans;
  int ind = lower_bound(all(v2), cnt) - v2.begin();
  debug(ind) for (int i = ind; i >= 1; i--) {
    if (v1[i - 1].second < v1[i].first) {
      for (auto it = mp.find(v1[i].first); it != mp.end(); it++) {
        for (auto j : (*it).second) {
          vans.pb(j);
        }
      }
    }
  }
  if (vans.size() == 0) {
    cout << n << endl;
    for (int i = 0; i < n; i++)
      cout << i + 1 << " ";
    return;
  }
  cout << vans.size() << endl;
  sort(all(vans));
  for (auto i : vans)
    cout << i + 1 << " ";
  debug(cnt, v1, v2)
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
