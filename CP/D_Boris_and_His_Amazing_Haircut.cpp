/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 04-01-2023 10:37:57
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
  vector<int> v(n), v1(n);
  for (auto &i : v)
    cin >> i;
  for (auto &i : v1)
    cin >> i;
  cin >> m;
  multiset<int> mltst;
  vector<int> vx(m);
  for (auto &i : vx)
    cin >> i, mltst.insert(i);
  // Segment tree
  vector<int> seg(4 * n);
  function<void(int, int, int)> build = [&](int ind, int low, int high) {
    if (low == high) {
      seg[ind] = v1[low];
      return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
  };
  function<int(int, int, int, int, int)> query = [&](int ind, int low, int high,
                                                     int l, int r) {
    if (low >= l && high <= r) {
      return seg[ind];
    }
    if (high < l || low > r)
      return -INF;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
  };
  build(0, 0, n - 1);
  debug(query(0, 0, n - 1, 0, n - 1));
  map<int, vector<int>> mpv;
  for (int i = 0; i < n; i++) {
    if (v[i] > v1[i])
      mpv[v1[i]].pb(i);
    if (v[i] < v1[i]) {
      cout << "NO";
      return;
    }
  }
  debug(mpv);
  while (mpv.size()) {
    vector<int> vt;
    auto [l, r] = *mpv.rbegin();
    mpv.erase(l);
    int en = r.back();
    vt.pb(en);
    r.pop_back();
    while (r.size()) {
      int ind = r.back();
      int mx = query(0, 0, n - 1, ind, en);
      if (mx <= l) {
        vt.pb(r.back());
        r.pop_back();
      } else
        break;
    }
    if (mltst.find(l) == mltst.end()) {
      cout << "NO";
      return;
    } else {
      mltst.erase(mltst.find(l));
    }
    for (auto i : vt) {
      v[i] = l;
    }
    if (r.size())
      mpv.insert({l, r});
    debug(mpv)
  }
  debug(v);
  for (int i = 0; i < n; i++) {
    if (v[i] != v1[i]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
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
