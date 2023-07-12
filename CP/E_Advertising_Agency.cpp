/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 11-06-2023 16:03:00
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

int func(vector<int> &v, int n, int k, int sum) {
  if (sum == 0 && k == 0) {
    return 1;
  }
  if (n == 0 || sum <= 0 || k == 0)
    return 0;
  int choose = func(v, n - 1, k - 1, sum - v[n - 1]);
  int nchoose = func(v, n - 1, k, sum);
  return choose + nchoose;
}

// nCr = n! * 1/r! * 1/(n-r)!

vector<int> fact(MAX_N, 1), invFact(MAX_N, 1);

int nCr(int n, int r) {
  if (r > n) {
    return 0;
  }
  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int bin_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (!(p & 1)) {
      (a *= a) %= MOD;
      p /= 2;
    } else {
      (res *= a) %= MOD;
      p--;
    }
  }
  return res;
}

void pref() {
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = bin_pow(fact[i], MOD - 2);
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  map<int, int> freq;
  for (auto &i : v)
    cin >> i, freq[i]++;
  sort(rall(v));
  for (int i = 0; i < k; i++)
    sum += v[i];
  int x = v[k - 1];
  int ind = -1;
  for (int i = k - 1; i >= 0; i--) {
    if (v[i] > x) {
      ind = i;
      break;
    }
  }
  int nos = k - 1 - ind;
  cout << nCr(freq[x], nos);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  cout << fixed;
  pref();
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
