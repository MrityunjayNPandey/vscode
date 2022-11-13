/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 09-11-2022 03:27:41
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

vector<int> factorial(MAX_N, 1);

int power(int a, int b) {

  if (b == 0)
    return 1;
  int res = 1;
  while (b > 0) {
    if (b & 1)
      (res *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return res % mod;
}

int modInv(int a, int m) { return power(a, m - 2); }

void fact() {
  for (int i = 1; i < MAX_N; i++) {
    factorial[i] = factorial[i - 1] * i % mod;
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for (auto &i : v)
    cin >> i, mp[i]++; 
  sort(all(v));
  // Permutation*permutation=permutation
  if (v[n - 1] == v[n - 2])
    cout << factorial[n];
  else {
    if (v[n - 1] - v[n - 2] > 1)
      cout << 0;
    else {
      int x = factorial[n];
      (x *= modInv(mp[v[n - 2]] + 1, mod)) %= mod;
      cout << (factorial[n] - x + mod) % mod;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
  fact();
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
