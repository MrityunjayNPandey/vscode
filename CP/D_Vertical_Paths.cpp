/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 13-11-2022 15:29:19
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
// fdffdgfgfdgfdfg
void solve() {
  map<int, bool> visited;
  map<int, vector<int>> adj_list;      // adjacency list
  map<pair<int, int>, int> adj_weight; // to add weights on edges
  vector<vector<int>> vv;
  vector<int> v1;
  function<void(int)> DFS = [&](int current) {
    visited[current] = true;
    for (int next_vertex : adj_list[current])
      if (!visited[next_vertex]) {
        debug(next_vertex);
        v1.pb(next_vertex);
        DFS(next_vertex);
        if (v1.size())
          vv.pb(v1);
        v1.clear();
        debug(next_vertex)
      }
  };
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  int root;
  for (int i = 0; i < n; i++) {
    if (v[i] != i + 1) {
      adj_list[i + 1].pb(v[i]);
      adj_list[v[i]].pb(i + 1);
    } else
      root = v[i];
  }
  debug(root);
  v1.pb(root);
  DFS(root);
  // debug(adj_list, vv);
  // if (!vv.size()) {
  //   cout << 1 << endl << 1 << endl << 1 << endl;
  //   return;
  // }
  // cout << vv.size() << endl;
  // for (auto i : vv) {
  //   cout << i.size() << endl;
  //   for (auto it : i)
  //     cout << it << " ";
  //   cout << endl;
  // }
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
