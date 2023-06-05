/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-05-2023 03:27:05
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
  cin >> n >> k;
  if ((n & k) != k) {
    cout << -1;
    return;
  }
  string str = bitset<64>(n).to_string();
  string str1 = bitset<64>(k).to_string();
  debug(str, str1);
  reverse(all(str));
  reverse(all(str1));
  int ind = -1;
  for (int i = 0; i < str.size(); i++) {
    if (str1[i] == '0' && str[i] == '1') {
      ind = i;
    }
  }
  if (ind == -1) {
    cout << n;
    return;
  }
  sum = 0;
  for (int i = 0; i < ind; i++) {
    if (str[i] == '1') {
      sum += 1LL << i;
    }
  }
  n += (1LL << ind) - sum;
  debug(n, bitset<64>(n).to_string());
  if ((n & k) != k) {
    cout << -1;
    return;
  }
  debug(sum);
  cout << n;
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