/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-07-2023 21:52:51
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  debug(v) vector<pair<int, int>> vp1, vp2;
  int init = -1, tw = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] > 0) {
      if (init == -1) {
        init = i;
      }
      if (v[i] == 2) {
        tw = 2;
      }
    } else {
      if (init != -1) {
        if (tw == 2) {
          vp2.pb({init, i - 1});
        } else {
          vp1.pb({init, i - 1});
        }
      }
      init = -1;
      tw = -1;
    }
    debug(init)
  }
  if (init != -1) {
    if (tw == 2) {
      vp2.pb({init, n - 1});
    } else {
      vp1.pb({init, n - 1});
    }
  }
  vector<int> vans(n);
  debug(vp1, vp2);
  ans += vp1.size();
  for (auto &[l, r] : vp2) {
    if (l > 0) {
      vans[l - 1] = 2;
    }
    for (int i = l; i <= r; i++) {
      vans[i] = 2;
    }
    if (r < n - 1) {
      vans[r + 1] = 2;
    }
  }
  for (auto &[l, r] : vp1) {
    cnt = 0;
    if (l > 0 && vans[l - 1] == 0) {
      vans[l - 1] = 1;
      cnt++;
    }
    for (int i = l; i <= r; i++) {
      vans[i] = 1;
    }
    if (!cnt) {
      if (r + 1 < n) {
        vans[r + 1] = 1;
      }
    }
  }
  debug(vans);
  ans += vp2.size();
  for (auto &i : vans) {
    if (i == 0) {
      ans++;
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
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
