/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 10-11-2022 16:31:50
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
  int l, r;
  cin >> n >> l >> r;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  multiset<int> lmlt, rmlt;
  for (int i = 0; i < n; i++) {
    if (i < l)
      lmlt.insert(v[i]);
    else
      rmlt.insert(v[i]);
  }
  vector<int> temp;
  for (auto i : lmlt) {
    if (rmlt.find(i) != rmlt.end()) {
      temp.pb(i);
      rmlt.erase(rmlt.lower_bound(i));
    }
  }
  for (auto i : temp) {
    lmlt.erase(lmlt.lower_bound(i));
  }
  map<int, int> mp1, mp2;
  for (auto i : lmlt)
    mp1[i]++;
  for (auto i : rmlt)
    mp2[i]++;
  debug(lmlt, rmlt);
  int p = lmlt.size(), q = rmlt.size();
  if (p < q) {
    int k = (q - p) / 2;
    for (auto &i : mp2) {
      while (i.second >= 2 && k) {
        ans++;
        i.second -= 2;
        k--;
      }
    }
    vector<int> temp;
    for (auto i : mp2) {
      if (i.second == 0) {
        temp.pb(i.first);
      }
    }
    for (auto i : temp)
      mp2.erase(i);
    multiset<int> rmlt1;
    for (auto i : mp2) {
      int k = i.second;
      while (k--)
        rmlt1.insert(i.first);
    }
    int p = lmlt.size(), q = rmlt1.size();
    debug(p, q);
    ans += min(p, q);
    int x = p, y = q;
    p -= min(x, y);
    q -= min(x, y);
    debug(rmlt1, ans, p, q);
    ans += max(p, q);
    cout << ans;
  } else if (p > q) {
    int k = (p - q) / 2;
    for (auto &i : mp1) {
      while (i.second >= 2 && k) {
        ans++;
        i.second -= 2;
        k--;
      }
    }
    vector<int> temp;
    for (auto i : mp1) {
      if (i.second == 0) {
        temp.pb(i.first);
      }
    }
    for (auto i : temp)
      mp1.erase(i);
    multiset<int> lmlt1;
    for (auto i : mp1) {
      int k = i.second;
      while (k--)
        lmlt1.insert(i.first);
    }
    int p = lmlt1.size(), q = rmlt.size();
    ans += min(p, q);
    int x = p, y = q;
    p -= min(x, y);
    q -= min(x, y);
    debug(lmlt1, ans, p, q);
    ans += max(p, q);
    cout << ans;
  } else
    cout << p;
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
