/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 31-05-2023 15:14:32
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
#define pb emplace_back
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
  string str1, str2;
  cin >> str1 >> str2;
  set<char> st, temp;
  for (auto i : str1) {
    st.insert(i);
  }
  vector<char> v;
  for (auto i : st) {
    v.pb(i);
  }
  k = min(k, (int)v.size());
  debug(v) int x = 0;
  while (k--) {
    x += 1 << k;
  }
  string comb1 = bitset<10>(x).to_string(), comb;
  x = v.size();
  int ind = 9;
  while (x--) {
    comb += comb1[ind];
    ind--;
  }
  reverse(all(comb));
  debug(comb, comb1);
  do {
    set<int> st1;
    for (int i = 0; i < comb.size(); i++) {
      if (comb[i] == '1') {
        st1.insert(v[i]);
      }
    }
    cnt = 0;
    int t1 = 0;
    for (int j = 0; j < n; j++) {
      if (st1.contains(str1[j]) || str1[j] == str2[j]) {
        cnt++;
      } else {
        t1 += (cnt * (cnt + 1)) / 2;
        cnt = 0;
      }
    }
    if (cnt) {
      t1 += (cnt * (cnt + 1)) / 2;
    }
    ans = max(ans, t1);
  } while (next_permutation(all(comb)));
  cout << ans;
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
