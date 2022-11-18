/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 17-11-2022 16:06:18
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
  int n = 0, m = 0, k = 0, ans = INF, cnt = 0, sum = 0;
  cin >> n;
  int n1 = n;
  int fact = n;
  int c = 2;
  vector<int> pfact;
  while (n % 2 == 0) {
    pfact.pb(2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    // While i divides n, print i and divide n
    while (n % i == 0) {
      pfact.pb(i);
      n = n / i;
    }
  }
  if (n > 2)
    pfact.pb(n);
  debug(pfact);
  map<int, int> mp;
  int freq = 1;
  for (auto i : pfact) {
    mp[i]++;
    if (mp[i] > freq)
      fact = i, freq = mp[i];
  }
  debug(fact) vector<int> vans;
  while (n1 % fact == 0)
    vans.pb(fact), n1 /= fact;
  debug(vans) vans.back() *= n1;
  cout << vans.size() << endl;
  for (auto i : vans)
    cout << i << " ";
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
