/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 17-12-2022 22:08:51
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
  cin >> n >> m;
  vector<vector<int>> vv(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vv[i][j];
      if (vv[i][j] == 1)
        cnt++;
    }
  }
  int equal = cnt / n;
  debug(vv);
  if (cnt % n) {
    cout << -1;
    return;
  }
  multimap<int, int> mp;
  map<int, vector<int>> mpv;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < m; j++) {
      if (vv[i][j] == 1) {
        temp++;
      }
    }
    debug(temp);
    if (temp != cnt / n) {
      mp.insert({temp, i});
    }
  }
  debug(mp);
  debug(equal, cnt);
  vector<tuple<int, int, int>> vtans;
  while (mp.size()>1) {
    auto [l, r] = *mp.begin();
    int l1 = l, r1 = r;
    auto [p, q] = *mp.rbegin();
    int p1 = p, q1 = q;
    debug(q, r, l1, p1);
    for (int i = 0; i < m; i++) {
      if (vv[q][i] == 1 && vv[r][i] == 0) {
        swap(vv[q][i], vv[r][i]);
        l1++, p1--;
        vtans.pb({q, r, i});
      }
      if (l1 == equal || p1 == equal) {
        break;
      }
      debug(l1, p1);
    }
    debug(l1, p1);
    int z1, z2;
    if (l1 == equal) {
      mp.erase(mp.begin());
      z1++;
    }
    if (p1 == equal) {
      mp.erase(prev(mp.end()));
      z2++;
    }
    if (!z1) {
      mp.erase(mp.begin());
      mp.insert({l1, r});
    }
    if (!z2) {
      mp.erase(prev(mp.end()));
      mp.insert({p1, q});
    }
    debug(mp);
  }
  cout << vtans.size() << endl;
  for (auto [p, q, r] : vtans) {
    cout << p + 1 << " " << q + 1 << " " << r + 1 << endl;
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
