/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-01-2023 20:33:02
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
  vector<int> v(n), ans1(n), ans2(n), l1, l2;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp[-v[i]].pb(i);
    cnt = max(cnt, v[i]);
  }
  set<int> st1, st2;
  for (int i = 1; i <= cnt; i++) {
    st1.insert(i);
    st2.insert(i);
  }
  debug(mp);
  for (auto [l, r] : mp) {
    if (r.size() > 2) {
      cout << "NO\n";
      return;
    } else if (r.size() == 1) {
      ans1[r[0]] = ans2[r[0]] = -l;
    } else {
      ans1[r[0]] = ans2[r[1]] = -l;
      l2.pb(r[0]);
      l1.pb(r[1]);
    }
    st1.erase(-l);
    st2.erase(-l);
  }
  debug(l1, l2);
  debug(ans1, ans2, st1, st2);
  for (int i = 0; i < l1.size(); i++) {
    if (ans1[l1[i]] == 0) {
      if (st1.empty()) {
        cout << "NO\n";
        return;
      }
      ans1[l1[i]] = *prev(st1.end());
      st1.erase(*prev(st1.end()));
    }
    if (ans2[l2[i]] == 0) {
      if (st2.empty()) {
        cout << "NO\n";
        return;
      }
      ans2[l2[i]] = *prev(st2.end());
      st2.erase(*prev(st2.end()));
    }
  }
  if (st1.size() || st2.size()) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (max(ans1[i], ans2[i]) != v[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES" << endl;
  for (auto i : ans1)
    cout << i << " ";
  cout << endl;
  for (auto i : ans2)
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
    // cout << endl;
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
