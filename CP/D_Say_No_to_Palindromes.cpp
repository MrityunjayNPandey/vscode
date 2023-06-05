/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-06-2023 17:31:24
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
#define pb emplace_back
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
  string str;
  cin >> str;
  string str1 = "abc";
  vector<vector<int>> vv;
  do {
    vector<int> temp(n);
    k = 0;
    for (int i = 0; i < n; i++) {
      if (str1[k] != str[i]) {
        temp[i]++;
      }
      if (i >= 1)
        temp[i] += temp[i - 1];
      k++;
      if (k == 3)
        k = 0;
    }
    debug(str1);
    vv.pb(temp);
  } while (next_permutation(all(str1)));
  debug(vv);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x == y) {
      ans = 0;
    } else if (x == 0) {
      ans = INF;
      for (auto &i : vv) {
        ans = min(ans, i[y]);
      }
    } else {
      ans = INF;
      for (auto &i : vv) {
        ans = min(ans, i[y] - i[x - 1]);
      }
    }
    cout << ans << endl;
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
