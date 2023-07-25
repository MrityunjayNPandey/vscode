/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-07-2023 21:51:31
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

int minCost(int x, vector<int> &cost, vector<int> &v,  map<int, vector<int>> &mp) {
  if (cost[x] != -1) {
    return cost[x];
  }
  if (mp.contains(x)) {
    int sum = 0;
    for (auto &i : mp[x]) {
      sum += minCost(i, cost, v, mp);
    }
    return cost[x] = min(v[x], sum);
  }
  return cost[x] = v[x];
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    v[x - 1] = 0;
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y;
      mp[i].pb(y - 1);
    }
  }
  vector<int> cost(n, -1);
  for (int i = 0; i < n; i++) {
    cout << minCost(i, cost, v, mp) << " ";
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
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
