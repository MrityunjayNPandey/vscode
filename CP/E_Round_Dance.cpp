/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-05-2023 21:49:09
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
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  debug(v) map<int, bool> visited;
  map<int, set<int>> adj_list; // adjacency list
  bool flag = false;
  function<void(int)> DFS = [&](int current) {
    visited[current] = true;
    if (adj_list[current].size() == 1) {
      flag = true;
    }
    for (int next_vertex : adj_list[current])
      if (!visited[next_vertex]) {
        DFS(next_vertex);
      }
  };
  for (int i = 0; i < n; i++) {
    adj_list[i + 1].insert(v[i]);
    adj_list[v[i]].insert(i + 1);
  }
  int minrd = 0, extrard = 0;
  for (int i = 1; i <= n; i++) {
    flag = false;
    if (!visited[i]) {
      DFS(i);
      if (flag) {
        extrard++;
      } else {
        minrd++;
      }
    }
  }
  debug(minrd, extrard);
  cout << minrd + ((extrard) ? 1 : 0) << " " << minrd + extrard;
  debug(adj_list);
  cout << endl;
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
  }
}
