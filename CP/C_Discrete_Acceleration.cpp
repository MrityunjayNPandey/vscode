/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 23-11-2022 21:44:22
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

double mindbl(double num1, double num2) {
  if (num1 < num2) {
    return num1;
  } else {
    return num2;
  }
}
double maxdbl(double num1, double num2) {
  if (num1 > num2) {
    return num1;
  } else {
    return num2;
  }
}

void solve() {
  double n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  double l = 0;
  cin >> n >> l;
  vector<double> v(n);
  for (auto &i : v)
    cin >> i;
  vector<double> t1, t2, dist, sp1, sp2;
  sp1.pb(1);
  sp2.pb(1);
  dist.pb(v[0]);
  double s1 = 2;
  t1.pb(v[0]);
  for (double i = 1; i < n; i++) {
    t1.pb((v[i] - v[i - 1]) / s1);
    t1[i] += t1[i - 1];
    sp1.pb(s1);
    dist.pb(v[i] - v[i - 1]);
    s1++;
  }
  sp1.pb(s1);
  dist.pb(l - v[n - 1]);
  t1.pb(l - v[n - 1] / s1);
  t1[n] += t1[n - 1];
  s1 = 2;
  t2.pb(l - v[n - 1]);
  cnt = 1;
  for (double i = n - 1; i >= 1; i--) {
    t2.pb((v[i] - v[i - 1]) / s1);
    t2[cnt] += t2[cnt - 1];
    sp2.pb(s1);
    cnt++;
    s1++;
  }
  sp2.pb(s1);
  t2.pb(v[0] / s1);
  t2[n] += t2[n - 1];
  reverse(all(t2));
  reverse(all(sp2));
  t2.pb(0);
  t1.insert(t1.begin(), 0);
  debug(t1, t2, dist, sp1, sp2);
  int ind = 0;
  double mn = INF;
  for (int i = 0; i < t1.size() - 1; i++) {
    if (t1[i] >= t2[i + 1]) {
      double spt = sp2[i];
      double time = (dist[i] - spt * (t1[i] - t2[i + 1])) / (sp1[i] + sp2[i]);
      if (spt * (t1[i] - t2[i + 1]) <= dist[i]) {
        cout << t1[i] + time;
        return;
      }
    } else {
      double spt = sp1[i];
      double time = (dist[i] - spt * (-t1[i] + t2[i + 1])) / (sp1[i] + sp2[i]);
      if (spt * (-t1[i] + t2[i + 1]) <= dist[i]) {
        cout << t2[i + 1] + time;
        return;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(15);
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
