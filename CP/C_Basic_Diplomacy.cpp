/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 10-06-2023 17:20:45
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
  cin >> n >> m;
  k = m;
  map<int, int> mp, freq;
  vector<int> vans;
  vector<vector<int>> vv;
  while (k--) {
    int sz;
    cin >> sz;
    vector<int> v(sz);
    int mx = INF, ind;
    for (auto &i : v) {
      cin >> i;
    }
    if (sz == 1) {
      mp[v[0]]++;
    }
    vv.pb(v);
  }
  for (auto i : vv) {
    if (i.size() > 1) {
      int mx = INF, ind;
      for (auto j : i) {
        if (mp[j] < mx) {
          mx = mp[j];
          ind = j;
        }
      }
      mp[ind]++;
      vans.pb(ind);
    } else
      vans.pb(i[0]);
  }
  for (auto &i : vans) {
    freq[i]++;
  }
  debug(vans) for (auto &[l, r] : freq) {
    if (r > (m + 1) / 2) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  for (auto &i : vans) {
    cout << i << " ";
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
    cout << endl;
  }
}
