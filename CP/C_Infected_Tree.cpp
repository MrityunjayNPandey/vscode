/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 01-12-2022 23:29:49
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
  map<int, vector<int>> adj_list;
  cin >> n;
  vector<int> count(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj_list[x].pb(y);
    adj_list[y].pb(x);
    sort(all(adj_list[x]));
    sort(all(adj_list[y]));
  }
  adj_list[1].pb(0);
  debug(adj_list);
  function<void(int, int)> numberOfNodes = [&](int s, int e) {
    count[s] = 1;
    for (auto &i : adj_list[s]) {
      if (i == e)
        continue;
      numberOfNodes(i, s);
      count[s] += count[i];
    }
  };
  numberOfNodes(1, 0);
  debug(count);
  int num = 1;
  vector<int> dp(n + 1, 0);
  // DFS, time complexity of O(V+E)
  map<int, bool> visited;
  visited[0] = true;
  function<void(int)> DFS = [&](int current) {
    visited[current] = true;
    debug(current);
    vector<int> child;
    for (int next_vertex : adj_list[current])
      if (!visited[next_vertex]) {
        child.pb(next_vertex);
        DFS(next_vertex);
      }
    debug(current);
    debug(child);
    if (child.size() == 0)
      return;
    if (child.size() == 1) {
      dp[current] = max(dp[current], count[child[0]] - 1);
      return;
    }
    dp[current] = max({dp[current], dp[child[0]] + count[child[1]] - 1, dp[child[1]] + count[child[0]] - 1});
  };
  DFS(1);
  cout << dp[1];
  debug(dp);
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

/*
Did I ever tell you what the definition of insanity is?
Insanity is doing the exact... same fucking thing... over and over again
expecting... shit to change... That. Is. Crazy. The first time somebody told me
that, I dunno, I thought they were bullshitting me. The thing is... He was
right. And then I started seeing, everywhere I looked, everywhere I looked all
these fucking pricks, everywhere I looked, doing the exact same fucking thing...
over and over and over and over again thinking 'this time is gonna be different'
no, no, no please... This time is gonna be different, I'm sorry, I don't like...
The way...

Okay, Do you have a fucking problem in your head, do you think I am bullshitting
you, do you think I am lying? Fuck you! Okay? Fuck you!...
*/
