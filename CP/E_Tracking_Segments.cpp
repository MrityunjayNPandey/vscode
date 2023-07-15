/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 15-07-2023 15:37:14
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

void solve() {
  int n = 0, m = 0, k = 0, ans = -1, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<pair<int, int>> vp(m);
  for (auto &[l, r] : vp) {
    cin >> l >> r;
  }
  debug(vp);
  cin >> k;
  vector<int> q(k);
  for (auto &i : q)
    cin >> i;
  debug(q);
  int l = 0, r = k;
  while (l <= r) {
    vector<int> v(n);
    int mid = (l + r) / 2;
    for (int i = 0; i < mid; i++) {
      v[q[i] - 1] = 1;
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + v[i - 1];
    }
    debug(v, pref);
    bool flag = false;
    for (auto &[l, r] : vp) {
      int num1 = pref[r] - pref[l - 1];
      int num0 = r - l + 1 - num1;
      debug(l, r, num1, num0);
      if (num1 > num0) {
        flag = true;
        break;
      }
    }
    if (flag) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
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
