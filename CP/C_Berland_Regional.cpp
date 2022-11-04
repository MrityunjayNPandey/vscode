/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 02-11-2022 04:05:10
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
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v1(n), v2(n), vv(n + 1);
  for (int i = 0; i < n; i++)
    cin >> v1[i];
  for (int i = 0; i < n; i++)
    cin >> v2[i], sum += v2[i];
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    mp[v1[i]].pb(v2[i]);
  }
  for (auto &i : mp) {
    sort(all(i.second));
  }
  debug(mp);
  for (auto &i : mp) {
    debug(i.second, i.second.size());
    for (int j = 1; j < i.second.size(); j++) {
      i.second[j] += i.second[j - 1];
    }
  }
  int p = 1;
  for (auto i : mp) {
    for (int p1 = 1; p1 <= i.second.size(); p1++) {
      int kp = i.second.size() % p1;
      if (kp == 0)
        vv[p1] += i.second.back();
      else
        vv[p1] += i.second.back() - i.second[--kp];
    }
  }
  for (int i = 1; i <= n; i++)
    cout << vv[i] << " ";
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
