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
  vector<int> v(n);
  map<int, vector<int>> mpv;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mpv[-v[i]].pb(i);
  }
  debug(mpv);
  for (auto [l, r] : mpv) {
    if (r.size() > 2) {
      cout << "NO";
      return;
    }
  }
  vector<int> v1(n), v2(n);
  set<int> st1, st2;
  for (auto [l, r] : mpv) {
    if (r.size() == 2) {
      v1[r[0]] = -l;
      v2[r[1]] = -l;
    } else {
      v1[r[0]] = -l;
      v2[r[0]] = -l;
    }
    st1.insert(-l);
    st2.insert(-l);
  }
  vector<int> vt1, vt2;
  for (int i = 1; i <= n; i++) {
    if (st1.find(i) == st1.end()) {
      vt1.pb(i);
    }
    if (st2.find(i) == st2.end()) {
      vt2.pb(i);
    }
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    if (v1[i] == 0) {
      v1[i] = vt1[k];
      k++;
    }
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    if (v2[i] == 0) {
      v2[i] = vt2[k];
      k++;
    }
  }
  debug(v1, v2);
  for (int i = 0; i < n; i++) {
    if (max(v1[i], v2[i]) != v[i]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  for (auto i : v1)
    cout << i << " ";
  cout << endl;
  for (auto i : v2)
    cout << i << " ";
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
