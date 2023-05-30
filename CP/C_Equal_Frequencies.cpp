/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 26-05-2023 23:37:09
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
  string str;
  cin >> str;
  map<char, int> mp;
  for (auto &i : str) {
    mp[i]++;
  }
  vector<int> v;
  for (auto [l, r] : mp) {
    v.pb(r);
  }
  sort(rall(v));
  vector<int> fact;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      if (i >= (n - 1) / 26 + 1)
        fact.pb(i);
      if (i != n / i)
        if (n / i >= (n - 1) / 26 + 1)
          fact.pb(n / i);
    }
  }
  sort(all(fact));
  debug(fact);
  int mn = INF, ansfact = 1;
  for (auto i : fact) {
    int left = 0, gr = n / i;
    for (int j = gr; j < v.size(); j++) {
      left += v[j];
    }
    for (int j = 0; j < gr && j < v.size(); j++) {
      if (v[j] > i) {
        left += v[j] - i;
      }
    }
    if (mn > left) {
      mn = left;
      ansfact = i;
    }
  }
  debug(mn, ansfact);
  map<char, set<int>> ind;
  for (int i = 0; i < n; i++) {
    ind[str[i]].insert(i);
  }
  debug(ind);
  multiset<pair<int, char>> mltst, imp;
  set<int> extra;
  for (auto [l, r] : mp) {
    mltst.insert({r, l});
  }
  k = n / ansfact;
  set<char> st;
  for (char i = 'a'; i <= 'z'; i++)
    st.insert(i);
  while (mltst.size() && k--) {
    st.erase((*mltst.rbegin()).second);
    imp.insert(*mltst.rbegin());
    mltst.erase(prev(mltst.end()));
  }
  for (auto [l, r] : mltst) {
    for (auto j : ind[r]) {
      extra.insert(j);
    }
  }
  vector<char> vans(n);
  debug(imp, extra, ind);
    for (auto &[l, r] : imp) {
      if (l > ansfact) {
        int x = l - ansfact;
        while (x--) {
          extra.insert(*ind[r].begin());
          ind[r].erase(ind[r].begin());
        }
      }
    }
    debug(imp, extra, ind);
    for (auto [l, r] : imp) {
      int x = ansfact;
      for (auto i : ind[r]) {
        vans[i] = r;
        x--;
      }
      while (x--) {
        vans[*extra.begin()] = r;
        extra.erase(extra.begin());
      }
    }
    k = 0;
    for (auto i : extra) {
      vans[i] = *st.begin();
      k++;
      if (k == ansfact) {
        k = 0;
        st.erase(st.begin());
      }
    }
    cout << mn << endl;
    for (auto i : vans)
      cout << i;
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
