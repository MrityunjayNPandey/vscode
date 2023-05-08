/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-05-2023 20:12:09
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
  cin >> n;
  set<int> both, first, second;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    string str;
    cin >> str;
    if (str == "11") {
      both.insert(x);
    } else if (str == "10") {
      first.insert(x);
    } else if (str == "01") {
      second.insert(x);
    }
  }
  if (!both.empty() && !first.empty() && !second.empty()) {
    int x = *both.begin();
    int y = *first.begin() + *second.begin();
    if (x < y) {
      cout << x;
    } else {
      cout << y;
    }
    return;
  }
  if (!both.empty()) {
    cout << *both.begin();
    return;
  }
  if (!first.empty() && !second.empty()) {
    int y = *first.begin() + *second.begin();
    cout << y;
    return;
  }
  cout << -1;
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
