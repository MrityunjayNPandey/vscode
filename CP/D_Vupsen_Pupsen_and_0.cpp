/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 04-06-2023 14:05:27
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
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<int> vans(n);
  if (n == 2) {
    int lcm = (abs(v[0]) * abs(v[1])) / __gcd(abs(v[0]), abs(v[1]));
    for (int i = 0; i < n; i++) {
      vans[i] = lcm / abs(v[i]);
      if (vans[i] * v[i] < 0) {
        vans[i] = -vans[i];
      }
    }
    vans[0] = -vans[0];
  } else {
    set<int> st;
    if (n & 1) {
      if (v[0] + v[1] != 0) {
        vans[0] = -v[2];
        vans[1] = -v[2];
        vans[2] = v[0] + v[1];
      } else if (v[2] + v[1] != 0) {
        vans[0] = v[2] + v[1];
        vans[1] = -v[0];
        vans[2] = -v[0];
      } else {
        vans[0] = -v[1];
        vans[1] = v[0] + v[2];
        vans[2] = -v[1];
      }
      st.insert(0);
      st.insert(1);
      st.insert(2);
    }
    set<int> st1;
    for (int i = 0; i < n; i++) {
      if (!st.contains(i))
        st1.insert(i);
    }
    while (!st1.empty()) {
      int l = *st1.begin();
      int r = *st1.rbegin();
      int lcm = (abs(v[l]) * abs(v[r])) / __gcd(abs(v[l]), abs(v[r]));
      vans[l] = lcm / abs(v[l]);
      if (vans[l] * v[l] < 0) {
        vans[l] = -vans[l];
      }
      vans[r] = lcm / abs(v[r]);
      if (vans[r] * v[r] < 0) {
        vans[r] = -vans[r];
      }
      vans[r] = -vans[r];
      st1.erase(l);
      st1.erase(r);
    }
  }
  for (auto i : vans)
    cout << i << " ";
  cout << endl;
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
  }
}
