/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 19-11-2022 01:24:14
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  int k1 = k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  sort(all(v));
  debug(v);
  int b = 1, g = 2;
  string permut = "BGG";
  do {
    debug(permut);
    // int ind = 0;
    // int ans1 = 0;
    // k = k1;
    // for (int i = 0; i < n; i++) {
    //   while (v[i] >= k) {
    //     int x;
    //     if (ind == 3)
    //       break;
    //     if (permut[ind] == 'B')
    //       x = 3;
    //     else
    //       x = 2;
    //     k *= x;
    //     ind++;
    //   }
    //   if (v[i] >= k)
    //     break;
    //   ans1++;
    //   k += v[i] / 2;
    // }
    // debug(ans1);
    // ans = max(ans, ans1);
  } while (next_permutation(all(permut)));
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
