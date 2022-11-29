/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-11-2022 13:27:55
 **/
// clang-format off
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#endif
#include <bits/stdc++.h>
using namespace std;
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
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = INT_MAX;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  vector<pair<int, int>> vp;
  int ind = 0;
  for (int i = 1; i < n; i++) {
    if (v[i] <= v[i - 1]) {
      vp.pb({ind, i - 1});
      ind = i;
    }
    debug(ind);
  }
  if (ind != n) {
    vp.pb({ind, n - 1});
  }
  debug(vp);
  n = vp.size();
  for (int i = 0; i < n - 1; i++) {
    int x = vp[i].second - vp[i].first;
    int y = vp[i + 1].second - vp[i + 1].first;
    if (y == 0 && i + 2 <= n - 1) {
      if (v[vp[i + 2].first] > v[vp[i].second]) {
        ans = max(ans, x + 1 + vp[i + 2].second - vp[i + 2].first + 1);
      }
    }
    if (v[vp[i + 1].first + 1] > v[vp[i].second])
      ans = max(ans, x + 1 + y);
    if (x > 0) {
      if (v[vp[i].second - 1] < v[vp[i + 1].first])
        ans = max(ans, x + y + 1);
    }
  }
  for (int i = 0; i < n; i++) {
    int x = vp[i].second - vp[i].first + 1;
    ans = max(ans, x);
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
  // cin >> Test;
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