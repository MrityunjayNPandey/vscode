/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-06-2023 22:14:25
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

int func(vector<int> &v, int a, int b, int p, int n, int pinit, int k7sat, int k3sat) {
  if (n < 0) {
    return 1;
  }
  int ans = 0;
  int temp = v[n];
  int k7satn = k7sat, k3satn = k3sat;
  if (n < 6 && k7sat) {
    temp += v[6] / 2;
    k7satn = 0;
  }
  if (n < 3 && k3sat) {
    temp += v[2] / 2;
    k3satn = 0;
  }
  if (p - temp >= 0) {
    ans = func(v, a, b, p - temp, n - 1, pinit, k7satn, k3satn);
    if (a)
      func(v, a - 1, b, p, n - 1, pinit, k7sat, k3sat);
  } else {
    if (a)
      ans = func(v, a - 1, b, p, n - 1, pinit, k7sat, k3sat);
    if (pinit >= temp && b) {
      ans = func(v, a, b - 1, pinit - temp, n - 1, pinit, k7satn, k3satn);
    }
  }
  return ans;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  vector<int> v(11);
  for (auto &i : v)
    cin >> i;
  cout << func(v, 3, 2, 10, 10, 10, 1, 1);
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
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    // cout << endl;
  }
}
