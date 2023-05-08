/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 02-05-2023 01:42:23
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

int FIND(int x, vector<int> &parent) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = FIND(parent[x], parent);
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int q;
  cin >> n >> q;
  vector<int> parent(n + 1), rank(n + 1, 1);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  map<int, int> point;
  while (q--) {
    string str;
    cin >> str;
    int x, y;
    if (str == "add") {
      cin >> x >> y;
      int p = FIND(x, parent);
      point[p] += y;
    } else if (str == "join") {
      cin >> x >> y;
      int p1 = FIND(x, parent);
      int p2 = FIND(y, parent);
      if (rank[p1] > rank[p2]) {
        parent[p2] = p1;
        rank[p1] += rank[p2];
        point[p1] += point[p2];
      } else {
        parent[p1] = p2;
        rank[p2] += rank[p1];
        point[p2] += point[p1];
      }
    } else {
      cin >> x;
      int p = FIND(x, parent);
      cout << point[p] << endl;
    }
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
