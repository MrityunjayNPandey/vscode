/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 23-07-2023 15:11:29
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

void func(vector<int> &v, vector<int> &pref, int l, int r, set<int> &st) {
  debug(l, r, pref[r + 1] - pref[l]);
  st.insert(pref[r + 1] - pref[l]);
  if (l == r || l < 0 || r < 0 || r > v.size() - 1 || l > v.size() - 1)
    return;
  int mid = v[l];
  mid += v[r];
  mid /= 2;
  mid = upper_bound(all(v), mid) - v.begin() - 1;
  if (mid >= l) {
    if (mid != r)
      func(v, pref, l, mid, st);
    if (mid + 1 != l)
      func(v, pref, mid + 1, r, st);
  }
  return;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<int> v(n), q(m), pref(n + 1);
  for (auto &i : v) {
    cin >> i;
  }
  for (auto &i : q) {
    cin >> i;
  }
  sort(all(v));
  set<int> st;
  for (int i = 1; i <= n; i++) {
    pref[i] += pref[i - 1] + v[i - 1];
  }
  debug(v);
  func(v, pref, 0, n - 1, st);
  debug(st);
  for (auto &i : q) {
    if (st.contains(i)) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
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
