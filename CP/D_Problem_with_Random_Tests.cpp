/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-10-2022 02:02:45
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
#define debug(...) 73
#define print(x) 73
#define dclear(x) 73
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  string str;
  cin >> n;
  cin >> str;
  vector<int> zer;
  int ind = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '1' && !k)
      k++, ind = i;
    if (k) {
      if (str[i] == '0')
        zer.pb(i);
    }
  }
  if (!k) {
    cout << 0;
    return;
  }
  int x = zer.size();
  if (x == 0) {
    for (int i = ind; i < n; i++)
      cout << str[i];
    return;
  }
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (i < zer[0])
      if (str[i] == '1') {
        st.insert(i);
      }
  }
  k = 0;
  while (x--) {
    set<int> st1;
    for (auto i : st) {
      if (str[i - zer[0] + zer[k]] == '1')
        st1.insert(i);
    }
    if (st1.size() == 1) {
      int j = 0;
      for (j = ind; j < zer[0]; j++)
        cout << str[j];
      for (int i = *st1.begin(); i <= *st1.begin() + n - zer[0] - 1; i++) {
        if (str[i] == '1' || str[j] == '1')
          cout << 1;
        else
          cout << 0;
        j++;
      }
      return;
    } else if (st1.size()) {
      st = st1;
    }
    k++;
  }
  int j = 0;
  for (j = ind; j < zer[0]; j++)
    cout << str[j];
  for (int i = *st.begin(); i <= *st.begin() + n - zer[0] - 1; i++) {
    if (str[i] == '1' || str[j] == '1')
      cout << 1;
    else
      cout << 0;
    j++;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      int Test = 1;
  //   cin >> Test;
  for (int I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    // cout << endl;
  }
}
