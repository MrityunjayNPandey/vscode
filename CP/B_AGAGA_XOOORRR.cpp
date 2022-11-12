/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 10-11-2022 13:59:05
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n), xorv(n + 1);
  for (auto &i : v)
    cin >> i;
  xorv[1] = v[0];
  for (int i = 2; i <= n; i++) {
    xorv[i] = xorv[i - 1] ^ v[i - 1];
  }
  debug(xorv);
  if (xorv[n] == 0) {
    for (int i = 1; i < n; i++) {
      if ((xorv[i] ^ xorv[0]) == (xorv[n] ^ xorv[i])) {
        cout << "YES";
        return;
      }
    }
    cout << "NO";
    return;
  }
  int ind = n;
  for (int i = 1; i < n; i++) {
    if (xorv[i] == xorv[n]) {
      ind = i;
      break;
    }
  }
  debug(ind);
  for (int i = ind; i < n; i++) {
    if (xorv[i] == 0) {
      cout << "YES";
      return;
    }
  }

  cout << "NO";
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