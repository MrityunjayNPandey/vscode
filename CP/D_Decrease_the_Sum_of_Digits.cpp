/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 23-11-2022 16:17:20
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  string str = to_string(n), strans;
  m = str.size();
  debug(str, k, n) vector<int> vd(m);
  for (int i = 0; i < m; i++) {
    sum += str[i] - '0';
    vd[i] = str[i] - '0';
  }
  debug(sum, vd);
  for (int i = m - 1; i >= 1; i--) {
    if (sum <= k)
      break;
    if (vd[i] > 0) {
      vd[i - 1]++;
      sum -= vd[i];
      sum += 1;
      vd[i] = 0;
    }
    debug(vd, sum)
  }
  if (sum > k) {
    sum -= vd[0];
    vd[0] = 0;
    strans += '1';
  }
  debug(m);
  for (int i = m - 1; i >= 1; i--) {
    if (vd[i] == 10) {
      vd[i - 1]++;
      vd[i] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (vd[i] == 10)
      strans += "10";
    else
      strans += vd[i] + '0';
  }
  debug(vd, strans);
  cout << stoll(strans) - n << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
