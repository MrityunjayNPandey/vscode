/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 16-07-2023 00:47:41
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

// nCr = n! * 1/r! * 1/(n-r)!

vector<int> fact(MAX_N, 1), invFact(MAX_N, 1);

int bin_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (!(p & 1)) {
      (a *= a) %= mod;
      p /= 2;
    } else {
      (res *= a) %= mod;
      p--;
    }
  }
  return res;
}

void pref() {
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invFact[i] = bin_pow(fact[i], mod - 2);
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, cnt1 = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  for (int i = 0; i < n; i += 3) {
    vector<int> vt(3);
    for (int j = 0; j < 3; j++) {
      vt[j] = v[i + j];
    }
    sort(all(vt));
    debug(vt);
    if (vt[0] == vt[1] && vt[1] == vt[2])
      cnt++;
    else if (vt[0] == vt[1])
      cnt1++;
  }
  int mult = 1;
  (mult = (fact[n / 3] * invFact[n / 6]) % mod * invFact[n / 6]) %= mod;
  debug(n, cnt, cnt1, mult);
  (mult *= bin_pow(3, cnt)) %= mod;
  (mult *= bin_pow(2, cnt1)) %= mod;
  cout << mult;
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
  //   cin >> Test;
  pref();
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
