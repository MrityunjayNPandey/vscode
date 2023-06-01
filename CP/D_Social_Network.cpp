/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 01-06-2023 04:01:25
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

int find(vector<int> &parent, int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = find(parent, parent[x]);
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> parent(n + 1), deg(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  debug(parent, deg);
  int extra = 0;
  while (k--) {
    int x, y;
    cin >> x >> y;
    int px = find(parent, x), py = find(parent, y);
    if (px == py) {
      extra++;
    } else {
      if (deg[px] > deg[py]) {
        deg[px] += deg[py];
        parent[py] = px;
      } else {
        deg[py] += deg[px];
        parent[px] = py;
      }
    }
    priority_queue<int> pq;
    for (int i = 1; i < n + 1; i++) {
      if (parent[i] == i) {
        pq.push(deg[i]);
      }
    }
    int temp = min(extra + 1, (int)pq.size());
    sum = 0;
    while (temp--) {
      sum += pq.top();
      pq.pop();
    }
    debug(sum);
    debug(parent, deg);
    ans = max({ans, deg[px], deg[py], sum});
    cout << ans - 1 << endl;
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
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
