/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 11-11-2022 01:32:46
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
  int n = 0, m = 0, k = 0, ans = INF, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<int> vodd, veven;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      veven.pb(v[i]);
    else
      vodd.pb(v[i]);
  }
  vector<int> vomin(vodd.size(), INF), vemin(veven.size(), INF);
  vomin[0] = vodd[0];
  vemin[0] = veven[0];
  for (int i = 1; i < vodd.size(); i++) {
    vomin[i] = min(vomin[i - 1], vodd[i]);
  }
  for (int i = 1; i < veven.size(); i++) {
    vemin[i] = min(vemin[i - 1], veven[i]);
  }
  for (int i = 1; i < vodd.size(); i++) {
    vodd[i] += vodd[i - 1];
  }
  for (int i = 1; i < veven.size(); i++) {
    veven[i] += veven[i - 1];
  }
  debug(v, vomin, vemin, vodd, veven);
  int p = 0, q = 0;
  ans = min(ans, n * v[0] + n * v[1]);
  debug(ans) for (int i = 2; i < n; i++) {
    if (i & 1) {
      q++;
    } else {
      p++;
    }
    debug(p, q);
    ans = min(ans, veven[q] - vemin[q] + (n - q) * (vemin[q]) + vodd[p] - vomin[p] + (n - p) * (vomin[p]));
  }
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
