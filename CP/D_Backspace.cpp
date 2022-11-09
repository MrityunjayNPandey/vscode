/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 09-11-2022 17:26:46
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
  string str, str1;
  cin >> str >> str1;
  n = str.size();
  vector<int> v;
  for (int i = 0; i < n; i++) {
    if (str[i] == str1[0]) {
      if (v.empty())
        v.pb(i);
      else if ((v[0] & 1) != (i & 1)) {
        v.pb(i);
        break;
      }
    }
  }
  debug(v);
  if (v.size() && str1.size() == 1) {
    for (int i = 0; i < v.size(); i++) {
      if (((n - v[i]) & 1)) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  for (auto it : v) {
    int prev = it;
    k = 1;
    for (int i = it + 1; i < n; i++) {
      if ((prev & 1) != (i & 1)) {
        if (str[i] == str1[k]) {
          debug(prev, i, k);
          k++;
          prev = i;
          if (k >= str1.size()) {
            if (((n - i) & 1)) {
              cout << "YES" << endl;
              return;
            }
          }
        }
      }
    }
  }
  cout << "NO" << endl;
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
    // cout << endl;
  }
}
