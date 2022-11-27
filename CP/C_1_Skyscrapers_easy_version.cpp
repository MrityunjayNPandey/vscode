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

  // Segment tree
  function<void(int, int, int)> build = [&](int ind, int low, int high) {
    if (low == high) {
      seg[ind] = v[low];
      return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  };
  function<int(int, int, int, int, int)> query = [&](int ind, int low, int high, int l, int r) {
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
  int t = 0;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[v[i]].pb(i);
  }
  int ind = -1;
  debug(v);
  for (int i = 0; i < n; i++) {
    int st = 0;
    sum = 0;
    while (st <= i) {
      if (i == 4)
        debug(st);
      int mn = query(0, 0, n - 1, st, i);
      int ind = upper_bound(all(mp[mn]), i) - mp[mn].begin();
      ind--;
      sum += (mp[mn][ind] - st + 1) * mn;
      st = mp[mn][ind];
      if (st == i)
        break;
      st++;
    }
    int en = n - 1;
    while (en >= i) {
      if (i == 4)
        debug(en);
      int mn = query(0, 0, n - 1, i, en);
      int ind = lower_bound(all(mp[mn]), i) - mp[mn].begin();
      sum += (en - mp[mn][ind] + 1) * mn;
      en = mp[mn][ind];
      if (en == i)
        break;
      en--;
    }
    sum -= v[i];
    if (ans < sum) {
      ind = i;
      ans = sum;
    }
  }
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
