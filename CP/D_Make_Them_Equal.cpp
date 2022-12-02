/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 03-12-2022 03:15:06
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
// #define int long long
int Test, I, tnum;

// O(log(n)), representing powers in binary form.
int bin_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      (res *= a) %= MOD;
    }
    p >>= 1;
    (a *= a) %= MOD;
  }
  return res;
}

vector<int> steps(MAX_N, INF);

void pref() {
  steps[1] = 0;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= i; j++) {
      steps[i + i / j] = min(steps[i + i / j], steps[i] + 1);
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n), v1(n);
  for (auto &i : v)
    cin >> i;
  for (auto &i : v1)
    cin >> i;
  vector<vector<int>> dp(n + 1, vector<int>(min(k + 1, 12 * n + 1), -1));
  function<int(int, int)> func = [&](int ind, int k) {
    if (ind == n)
      return 0;
    debug(v[ind], steps[v[ind]]);
    if (dp[ind][min(k, 12 * n)] != -1)
      return dp[ind][min(k, 12 * n)];
    int choose = 0, nchoose = 0;
    if (steps[v[ind]] <= k) {
      choose = func(ind + 1, k - steps[v[ind]]) + v1[ind];
      nchoose = func(ind + 1, k);
    } else {
      nchoose = func(ind + 1, k);
    }
    return dp[ind][min(k, 12 * n)] = max(choose, nchoose);
  };
  cout << func(0, k) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
  pref();
  cout.precision(16);
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
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
