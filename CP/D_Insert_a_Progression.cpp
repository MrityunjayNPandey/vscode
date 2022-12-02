/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 02-12-2022 03:12:41
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, cnt1 = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 1 || v[i + 1] == 1)
      cnt++;
    ans += abs(v[i] - v[i + 1]);
  }
  if (k <= *max_element(all(v)))
    cnt1++;
  debug(cnt, cnt1, ans);
  if (cnt && cnt1) {
    cout << ans << endl;
  } else {
    if (cnt == 0) {
      int mn = abs(v[0] - 1) + ans;
      for (int i = 1; i < n; i++) {
        mn = min(mn, ans + abs(v[i] - 1) + abs(v[i - 1] - 1) -
                         abs(v[i] - v[i - 1]));
      }
      mn = min(mn, ans + abs(v[n - 1] - 1));
      ans = mn;
    }
    if (cnt1 == 0) {
      int mn = abs(v[0] - k) + ans;
      debug(mn);
      for (int i = 1; i < n; i++) {
        mn = min(mn, ans + abs(v[i] - k) + abs(v[i - 1] - k) -
                         abs(v[i] - v[i - 1]));
        debug(mn);
      }
      mn = min(mn, ans + abs(v[n - 1] - k));
      debug(mn);
      ans = mn;
    }
    cout << ans << endl;
  }
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
