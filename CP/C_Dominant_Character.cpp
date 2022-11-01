/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-10-2022 18:45:58
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
#define print(x) 73;
#define dclear(x) 73;
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

//v.size() returns unsigned value, always convert it into int to prevent any runtime error

void solve() {
  int n = 0, m = 0, k = 0, q = 0, ans = INF, cnt = 0, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'a')
      v.pb(i);
  }
  int n1 = v.size();
  for (int i = 0; i < n1 - 1; i++) {
    if (v[i + 1] - v[i] == 1)
      ans = 2;
    else if (v[i + 1] - v[i] == 2)
      ans = min(3LL, ans);
    else if (v[i + 1] - v[i] == 3) {
      if (str[v[i + 1] - 1] != str[v[i] + 1])
        ans = min(4LL, ans);
      if (i + 2 < n1) {
        if (v[i + 2] - v[i + 1] == 3) {
          if (str[v[i + 1] - 1] == str[v[i] + 1] &&
              str[v[i + 2] - 1] == str[v[i + 1] + 1] &&
              str[v[i + 2] - 1] != str[v[i] + 1])
            ans = min(7LL, ans);
        }
      }
    }
  }
  debug(ans);
  if (ans == INF)
    cout << -1;
  else
    cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
