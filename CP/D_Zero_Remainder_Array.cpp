/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 07-11-2022 23:05:26
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
#define print(x) 73;
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  map<int, int> mp;
  for (auto &i : v) {
    cin >> i, i %= k;
    if (i) {
      mp[k - i]++;
    }
  }
  debug(mp);
  int x = 0;
  while (mp.size()) {
    vector<int> vt;
    for (auto i : mp) {
      int p = i.first;
      if (p >= (x % k)) {
        ans += p - (x % k) + 1;
        x += p - (x % k);
      } else {
        ans += k - (x % k) + p + 1;
        x += k - (x % k) + p;
      }
      x++;
      mp[p]--;
      debug(x, ans);
      if (mp[p] <= 0)
        vt.pb(p);
    }
    for (auto i : vt)
      mp.erase(i);
    debug(mp, ans)
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
