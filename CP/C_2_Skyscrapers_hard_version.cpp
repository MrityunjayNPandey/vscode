/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-11-2022 17:37:16
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
  vector<int> v(n), seg(4 * n);
  for (auto &i : v)
    cin >> i;
  int t = 0;
  // Nearest Smaller elements O(n)
  vector<pair<pair<int, int>, pair<int, int>>> vNSE(n, {{-1, -1}, {-1, -1}});
  function<void(int)> NSE = [&](int n) {
    stack<pair<int, int>> S, S1;
    for (int i = 0; i < n; i++) {
      while (!S.empty() && S.top().first >= v[i])
        S.pop();
      if (!S.empty())
        vNSE[i] = {S.top(), vNSE[i].second};
      S.push({v[i], i});
    }
    for (int i = n - 1; i >= 0; i--) {
      while (!S1.empty() && S1.top().first >= v[i])
        S1.pop();
      if (!S1.empty())
        vNSE[i] = {vNSE[i].first, S1.top()};
      S1.push({v[i], i});
      debug(vNSE[i]);
    }
  };
  NSE(n);
  // DP implementation
  vector<pair<int, int>> sumv(n);
  for (int i = 0; i < n; i++) {
    if (vNSE[i].first.second == -1)
      sumv[i].first = (i + 1) * v[i];
    else
      sumv[i].first =
          (i - vNSE[i].first.second) * v[i] + sumv[vNSE[i].first.second].first;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (vNSE[i].second.second == -1)
      sumv[i].second = (n - i) * v[i];
    else
      sumv[i].second = (vNSE[i].second.second - i) * v[i] +
                       sumv[vNSE[i].second.second].second;
  }
  int ind = -1;
  for (int i = 0; i < n; i++) {
    if (sumv[i].first + sumv[i].second - v[i] > sum) {
      ind = i;
      sum = sumv[i].first + sumv[i].second - v[i];
    }
  }
  debug(sumv);
  int mx = v[ind];
  vector<int> vans(n);
  vans[ind] = v[ind];
  for (int j = ind - 1; j >= 0; j--) {
    if (v[j] > mx) {
      vans[j] = mx;
    } else {
      vans[j] = v[j];
      mx = v[j];
    }
  }
  mx = v[ind];
  for (int j = ind + 1; j < n; j++) {
    if (v[j] > mx) {
      vans[j] = mx;
    } else {
      vans[j] = v[j];
      mx = v[j];
    }
  }
  for (auto &i : vans)
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
