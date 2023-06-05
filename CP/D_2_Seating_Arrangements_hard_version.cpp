/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-06-2023 02:34:06
 **/
// clang-format off
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std; 
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
  cin >> n >> m;
  vector<int> v(n * m);
  priority_queue<int> pq;
  for (auto &i : v)
    cin >> i, pq.push(i);
  vector<vector<int>> vv(n, vector<int>(m));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      vv[i][j] = pq.top();
      pq.pop();
    }
  }
  debug(vv);
  for (int i = 0; i < n; i++) {
    multiset<int> mltst;
    for (int j = 0; j < m; j++) {
      mltst.insert(vv[i][j]);
    }
    vector<int> v1;
    for (auto &i : v) {
      if (mltst.contains(i)) {
        mltst.erase(mltst.lower_bound(i));
        v1.emplace_back(i);
        i = 0;
      }
      if (v1.size() == m)
        break;
    }
    debug(v1);
    multiset<int> omltst;
    for (auto i : v1) {
      omltst.insert(i);
      ans += distance(omltst.begin(), omltst.lower_bound(i));
    }
  }
  cout << ans;
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
