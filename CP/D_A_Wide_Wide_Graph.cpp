// clang-format off
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, sum = 0;
  cin >> n;
  map<int, vector<int>> adj_list;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj_list[x].pb(y);
    adj_list[y].pb(x);
  }
  map<int, bool> visited;
  map<pair<int, int>, int> adj_weight;
  int maxd = -1, node = -1;
  function<void(int, int)> DFSc = [&](int current, int d) {
    visited[current] = true;
    if (maxd < d) {
      maxd = d;
      node = current;
    }
    for (int next_vertex : adj_list[current])
      if (!visited[next_vertex]) {
        DFSc(next_vertex, d + 1);
      }
  };
  DFSc(1, 0);
  int end1 = node;
  visited.clear();
  maxd = -1;
  node = -1;
  DFSc(end1, 0);
  int end2 = node;
  debug(end1, end2);
  queue<int> q1, q2;
  map<int, bool> vis1, vis2;
  map<int, int> level1, level2;
  multiset<int> cnt1, cnt2;
  q1.push(end1);
  q2.push(end2);
  level1[end1] = 0;
  level2[end2] = 0;
  debug(level2);
  while (!q1.empty()) {
    vis1[q1.front()] = 1;
    for (auto i : adj_list[q1.front()]) {
      if (!vis1[i]) {
        q1.push(i);
        level1[i] = level1[q1.front()] + 1;
        cnt1.insert(level1[i]);
      }
    }
    q1.pop();
  }
  debug(adj_list) while (!q2.empty()) {
    vis2[q2.front()] = 1;
    for (auto i : adj_list[q2.front()]) {
      if (!vis2[i]) {
        q2.push(i);
        level2[i] = level2[q2.front()] + 1;
        cnt2.insert(level2[i]);
      }
    }
    q2.pop();
  }
  vector<int> vdist(n + 1);
  for (int i = 1; i <= n; i++) {
    vdist[i] = max(level1[i], level2[i]);
  }
  sort(all(vdist));
  debug(vdist);
  for (int i = 1; i <= n; i++) {
    int ind = lower_bound(all(vdist), i) - vdist.begin();
    int k = vdist.size() - ind;
    if (k == 0) {
      cout << n << " ";
      continue;
    }
    cout << n - k + 1 << " ";
  }
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
  // cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}