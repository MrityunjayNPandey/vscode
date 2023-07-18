/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-07-2023 02:17:08
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
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; //find_by_order(k), order_of_key(k)
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<pair<int, int>> vp(n);
  for (auto &[l, r] : vp) {
    cin >> l >> r;
  }
  // DFS, time complexity of O(V+E)
  map<int, bool> visited;
  map<int, vector<int>> adj_list; // adjacency list
  vector<vector<int>> dp(2, vector<int>(n + 1));
  function<void(int)> DFS = [&](int current) {
    visited[current] = true;
    auto [lv, rv] = vp[current - 1];
    for (int next_vertex : adj_list[current]) {
      if (!visited[next_vertex]) {
        DFS(next_vertex);
        auto [lvs, rvs] = vp[next_vertex - 1];
        dp[0][current] += max(abs(lv - lvs) + dp[0][next_vertex], abs(lv - rvs) + dp[1][next_vertex]);
        dp[1][current] += max(abs(rv - lvs) + dp[0][next_vertex], abs(rv - rvs) + dp[1][next_vertex]);
      }
    }
  };
  for (int i = 0; i < n - 1; i++) {
    auto [l, r] = pair<int, int>();
    cin >> l >> r;
    adj_list[l].pb(r);
    adj_list[r].pb(l);
  }
  DFS(1);
  debug(dp, dp.size(), dp[0].size());
  cout << max(dp[0][1], dp[1][1]);
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
