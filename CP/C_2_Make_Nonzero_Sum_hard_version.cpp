/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 24-10-2022 12:03:27
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
#define debug(...) 
#define print(x)
#define dclear(x)
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  int one = 0;
  vector<pair<int, int>> vp, vans;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 1 || v[i] == -1) {
      one++;
      vp.pb({v[i], i});
    }
  }
  debug(vp) if (one % 2) {
    cout << -1 << endl;
    return;
  }
  for (int i = 0; i < vp.size(); i += 2) {
    if (vp[i].first == vp[i + 1].first) {
      if (vp[i + 1].second == vp[i].second + 1) {
        vans.pb({vp[i].second, vp[i + 1].second});
      } else {
        vans.pb({vp[i].second, vp[i + 1].second - 2}),
            vans.pb({vp[i + 1].second - 1, vp[i + 1].second});
      }
    } else {
      vans.pb({vp[i].second, vp[i].second});
      if (vp[i + 1].second != vp[i].second + 1) {
        vans.pb({vp[i].second + 1, vp[i + 1].second - 1});
      }
      vans.pb({vp[i + 1].second, vp[i + 1].second});
    }
  }
  debug(vans);
  if (vans.size() == 0) {
    cout << 1 << endl;
    cout << 1 << " " << n << endl;
    return;
  }
  int temp1, temp2;
  for (auto i : vans) {
    if (k) {
      if (i.first != temp2 + 1)
        ans++;
    }
    k++, temp1 = i.first, temp2 = i.second;
  }
  ans += vans.size();
  if (vans[0].first != 0) {
    ans++;
  }
  if (vans[vans.size() - 1].second != n - 1) {
    ans++;
  }
  cout << ans << endl;
  if (vans[0].first != 0) {
    cout << 1 << " " << vans[0].first << endl;
  }
  k = 0;
  for (auto i : vans) {
    if (k) {
      if (i.first != temp2 + 1)
        cout << temp2 + 2 << " " << i.first << endl;
    }
    cout << i.first + 1 << " " << i.second + 1 << endl;
    k++, temp1 = i.first, temp2 = i.second;
  }
  if (vans[vans.size() - 1].second != n - 1) {
    cout << vans[vans.size() - 1].second + 2 << " " << n << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      int Test = 1;
  cin >> Test;
  for (int I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    // cout << endl;
  }
}
