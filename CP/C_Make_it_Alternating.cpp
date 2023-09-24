/**
 *      codeforces: _joKer_0
 *      created: 24-09-2023 20:30:44
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

vector<int> fact(MAX_N, 1);

void pref() {
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 1, cnt1 = 0, cnt2 = 0, sum = 0;
  string str;
  cin >> str;
  n = str.size();
  int st = str[0] - '0';
  for (int i = 0; i < n; i++) {
    if (str[i] - '0' == st) {
      cnt1++;
      st = !st;
    }
  }
  debug(cnt1);
  cout << n - cnt1 << " ";
  int extra = 0;
  st = str[0] - '0';
  for (int i = 0; i < n; i++) {
    if (st != str[i] - '0') {
      st = !st;
      (ans *= cnt2) %= mod;
      extra += max(cnt2 - 1, 0LL);
      cnt2 = 0;
    }
    cnt2++;
  }
  debug(cnt2, extra);

  extra += max(cnt2 - 1, 0LL);
  (ans *= cnt2) %= mod;

  cout << (fact[extra] * ans) % mod;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
  pref();
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
