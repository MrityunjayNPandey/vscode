/**
 *      codeforces: _joKer_0
 *      created: 09-10-2023 20:19:25
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
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; //find_by_order(k), order_of_key(k)
// clang-format on
#define int long long
int Test, I, tnum;

double dist(pair<double, double> &p1, pair<double, double> &p2) {
  auto &[p1x, p1y] = p1;
  auto &[p2x, p2y] = p2;
  return sqrt((p1x - p2x) * (p1x - p2x) + (p1y - p2y) * (p1y - p2y));
}

bool check(double distance, pair<double, double> &p1, pair<double, double> &p2,
           pair<double, double> &l1, pair<double, double> &l2) {
  if (distance >= dist(p1, l1) && distance >= dist(p2, l1))
    return true;
  if (distance >= dist(p1, l2) && distance >= dist(p2, l2))
    return true;
  if (distance >= dist(p1, l1) && distance >= dist(p2, l2) &&
      2 * distance >= dist(l1, l2))
    return true;
  if (distance >= dist(p1, l2) && distance >= dist(p2, l1) &&
      2 * distance >= dist(l1, l2))
    return true;
  return false;
};

void solve() {
  double n = 0, m = 0, ans = 0, cnt = 0, sum = 0;
  pair<double, double> p1 = {0, 0}, p2 = {0, 0}, l1 = {0, 0}, l2 = {0, 0};
  auto &[p1x, p1y] = p1;
  auto &[p2x, p2y] = p2;
  auto &[l1x, l1y] = l1;
  auto &[l2x, l2y] = l2;
  cin >> p2x >> p2y;
  cin >> l1x >> l1y;
  cin >> l2x >> l2y;
  double l = 0, r = 1e9;
  int k = 100;
  while (k--) {
    double mid = (l + r) / 2;
    if (check(mid, p1, p2, l1, l2)) {
      ans = mid;
      r = mid;
    } else
      l = mid;
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
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
