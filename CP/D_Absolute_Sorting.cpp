/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 18-12-2022 21:26:26
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
  vector<int> v1(n), v;
  for (auto &i : v1)
    cin >> i;
  v.pb(v1[0]);
  for (int i = 1; i < n; i++) {
    if (v.back() != v1[i]) {
      v.pb(v1[i]);
    }
  }
  n = v.size();
  int init = -1, init2 = -1, end = -1, end2 = -1;
  vector<pair<int, int>> inc, dec;
  for (int i = 1; i < n; i++) {
    if (v[i] >= v[i - 1]) {
      if (init2 != -1) {
        dec.pb({init2, end2});
      }
      init2 = -1, end2 = -1;
      if (init == -1) {
        init = i - 1;
      }
      end = i;
    } else {
      if (init != -1)
        inc.pb({init, end});
      init = -1, end = -1;
      if (init2 == -1) {
        init2 = i - 1;
      }
      end2 = i;
    }
  }
  if (init != -1) {
    inc.pb({init, end});
  }
  if (init2 != -1) {
    dec.pb({init2, end2});
  }
  debug(inc, dec);
  int maxd = INF;
  for (auto [l, r] : inc) {
    maxd = min(maxd, (v[l] + v[l + 1]) / 2);
  }
  debug(maxd);
  for (auto [l, r] : dec) {
    int diff = (v[l] + v[l + 1] + 1) / 2;
    debug(diff);
    if (diff > maxd) {
      cout << -1;
      return;
    }
    ans = max(ans, diff);
  }
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

/*
Did I ever tell you what the definition of insanity is?
Insanity is doing the exact... same fucking thing... over and over again
expecting... shit to change... That. Is. Crazy. The first time somebody told me
that, I dunno, I thought they were bullshitting me. The thing is... He was
right. And then I started seeing, everywhere I looked, everywhere I looked all
these fucking pricks, everywhere I looked, doing the exact same fucking thing...
over and over and over and over again thinking 'this time is gonna be different'
no, no, no please... This time is gonna be different, I'm sorry, I don't like...
The way...

Okay, Do you have a fucking problem in your head, do you think I am bullshitting
you, do you think I am lying? Fuck you! Okay? Fuck you!...
*/
