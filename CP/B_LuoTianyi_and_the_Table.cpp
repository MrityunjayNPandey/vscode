/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-05-2023 17:53:57
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
  cin >> n >> m;
  vector<int> v(n * m);
  multiset<int> mltst;
  for (auto &i : v)
    cin >> i, mltst.insert(i);
  // opn1:min and 2 max
  int x = *mltst.begin();
  int y = *prev(mltst.end());
  int z = *prev(prev(mltst.end()));
  if (n > m) {
    ans += (n - 1) * (y - x);
    ans += (m - 1) * (z - x);
  } else {
    ans += (m - 1) * (y - x);
    ans += (n - 1) * (z - x);
  }
  ans += (n - 1) * (m - 1) * (y - x);

  // opn 2: max and 2 min
  int ans1 = 0;
  int x1 = *prev(mltst.end());
  int y1 = *mltst.begin();
  int z1 = *next(mltst.begin());
  if (n > m) {
    ans1 += (n - 1) * (x1 - y1);
    ans1 += (m - 1) * (x1 - z1);
  } else {
    ans1 += (m - 1) * (x1 - y1);
    ans1 += (n - 1) * (x1 - z1);
  }
  ans1 += (n - 1) * (m - 1) * (x1 - y1);
  cout << max(ans, ans1);
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
