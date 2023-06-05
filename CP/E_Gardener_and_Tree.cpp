/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 01-06-2023 23:27:23
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
  cin >> n >> k;
  map<int, set<int>> adj_list; // adjacency list
  n--;
  while (n--) {
    int x, y;
    cin >> x >> y;
    adj_list[x].insert(y);
    adj_list[y].insert(x);
  }
  map<int, set<int>> deg;
  for (auto [l, r] : adj_list) {
    deg[r.size()].insert(l);
  }
  while (k--) {
    debug(deg[1], adj_list);
    if (deg[1].size() == 0) {
      debug(deg[0]) if (deg[0].size() == 1) { adj_list.erase(*deg[0].begin()); }
      break;
    }
    if (adj_list.size() == 2) {
      adj_list.erase(*deg[1].begin());
      adj_list.erase(*deg[1].rbegin());
      break;
    }
    set<int> st = deg[1];
    for (auto i : st) {
      int parent = *adj_list[i].begin();
      int initdeg = adj_list[parent].size();
      deg[initdeg].erase(parent);
      deg[initdeg - 1].insert(parent);
      if (adj_list.contains(parent))
        adj_list[parent].erase(i);
      adj_list.erase(i);
    }
    for (auto i : st) {
      deg[1].erase(i);
    }
  }
  cout << adj_list.size();
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
