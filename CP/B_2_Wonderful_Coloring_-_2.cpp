/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 31-10-2022 06:41:36
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
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  map<int, vector<int>> mp, unique, dupl, duplk;
  for (int i = 0; i < n; i++)
    cin >> v[i], mp[v[i]].pb(i);
  int duplsize = 0;
  for (auto i : mp) {
    if (i.second.size() == 1) {
      unique[i.first] = i.second;
    } else if (i.second.size() >= k) {
      duplk[i.first] = i.second;
    } else {
      dupl[i.first] = i.second;
      duplsize += i.second.size();
    }
  }
  debug(unique, duplk, dupl);
  vector<int> vans(n);
  for (auto i : duplk) {
    int k1 = 1;
    for (auto j : i.second) {
      if (k1 <= k)
        vans[j] = k1;
      else
        break;
      k1++;
    }
  }
  vector<int> vdupl, vunique;
  for (auto i : dupl) {
    for (auto j : i.second) {
      vdupl.pb(j);
    }
  }
  for (auto i : unique) {
    for (auto j : i.second) {
      vunique.pb(j);
    }
  }
  debug(vdupl, vunique)
      //   if (vdupl.size() % k == 0) {
      //     int k1 = 1;
      //     for (auto i : vdupl) {
      //       if (k1 == k + 1)
      //         k1 = 1;
      //       vans[i] = k1;
      //       k1++;
      //     }
      //   }
      debug(vans);
  if (vunique.size() >= k - vdupl.size() % k) {
    int k1 = 1;
    for (auto i : vdupl) {
      if (k1 == k + 1)
        k1 = 1;
      vans[i] = k1;
      k1++;
    }
    debug(vans);
    if (k1 == k + 1)
      k1 = 1;
    for (auto i : vunique) {
      if (k1 == k + 1)
        break;
      vans[i] = k1;
      k1++;
    }
    int p = vunique.size();
    int x = (p - (k - vdupl.size() % k)) / k;
    k1 = 1;
    int tempp = 0;
    for (int i = k - (vdupl.size() % k); i < vunique.size(); i++) {
      debug(i) if (k1 == k + 1) {
        k1 = 1;
        tempp++;
      }
      if (tempp == x)
        break;
      vans[vunique[i]] = k1;
      k1++;
    }
  } else {
    int p1 = vdupl.size();
    int x1 = p1 / k;
    int k1 = 1;
    int temp = 0;
    for (auto i : vdupl) {
      if (k1 == k + 1)
        k1 = 1, temp++;
      if (temp == x1)
        break;
      vans[i] = k1;
      k1++;
    }
    k1 = 1;
    temp = 0;
    int p2 = vunique.size();
    x1 = p2 / k;
    for (auto i : vunique) {
      if (k1 == k + 1)
        k1 = 1, temp++;
      if (temp == x1)
        break;
      vans[i] = k1;
      k1++;
    }
  }
  for (auto i : vans)
    cout << i << " ";
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
