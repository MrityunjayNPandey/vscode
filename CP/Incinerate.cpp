/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-12-2022 20:28:30
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
  cin >> n >> k;
  int kinit = k;
  vector<pair<int, int>> vp(n);
  for (auto &[l, r] : vp)
    cin >> l;
  for (auto &[l, r] : vp)
    cin >> r;
  sort(all(vp));
  debug(vp);
  vector<int> v1(n), v2(n);
  for (int i = 0; i < n; i++) {
    auto [l, r] = vp[i];
    v1[i] = l;
    v2[i] = r;
  }
  // Segment tree
  vector<int> seg(4 * n);
  function<void(int, int, int)> build = [&](int ind, int low, int high) {
    if (low == high) {
      seg[ind] = v2[low];
      return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  };
  function<int(int, int, int, int, int)> query = [&](int ind, int low, int high,
                                                     int l, int r) {
    if (low >= l && high <= r) {
      return seg[ind];
    }
    if (high < l || low > r)
      return INF;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(left, right);
  };
  build(0, 0, n - 1);
  debug(seg);
  debug(v1, v2);
  while (1) {
    int ind = upper_bound(all(v1), k) - v1.begin();
    if (ind == n) {
      cout << "YES";
      return;
    }
    int minp = query(0, 0, n - 1, ind, n - 1);
    debug(ind, n - 1, minp);
    kinit -= minp;
    if (kinit <= 0) {
      cout << "NO";
      return;
    }
    k += kinit;
    debug(k);
  }
  debug(v1, v2);
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
