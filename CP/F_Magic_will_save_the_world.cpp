/**
 *      codeforces: _joKer_0
 *      created: 24-08-2023 21:31:15
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

bool possible(vector<int> &v, int fire, int water, vector<int> &dp,
              int i = 0) {
  int n = v.size();
  if (i == n) {
    return true;
  }
  bool ans = false;
  if (dp[i] != -1)
    return dp[i];
  if (fire >= v[i]) {
    ans |= possible(v, fire - v[i], water, dp, i + 1);
  }
  if (water >= v[i]) {
    ans |= possible(v, fire, water - v[i], dp, i + 1);
  }
  return dp[i] = ans;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int w, f;
  cin >> w >> f;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  int l = 0, r = 1e9;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int water = mid * w;
    int fire = mid * f;
    vector<int> dp(n, -1);
    if (possible(v, fire, water, dp)) {
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