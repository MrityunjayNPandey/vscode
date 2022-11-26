/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-11-2022 21:26:16
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

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primetemp(MAX_N + 1, 1), isprime(MAX_N + 1, 0), prime;
void SIEVE() {
  prime.pb(1);
  isprime[1]++;
  for (int p = 2; p <= MAX_N; p++) {
    if (primetemp[p] == 1) {
      prime.pb(p);
      isprime[p]++;
      for (int i = p * p; i <= MAX_N; i += p) {
        primetemp[i] = 0;
      }
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int x;
  cin >> n >> x;
  int p = x;
  vector<int> v(n + 1, -1);
  v[1] = x;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    if (i != x) {
      st.insert(i);
    }
  }
  debug(st);
  if (st.find(1) != st.end()) {
    v[n] = 1;
    st.erase(1);
  }
  for (int i = 1; prime[i] <= n - 1; i++) {
    if (st.find(prime[i]) != st.end()) {
      v[prime[i]] = prime[i];
      st.erase(prime[i]);
    }
  }
  debug(v);
  if (n % x) {
    cout << -1;
    return;
  }
  while (n % x == 0 && x < n) {
    for (int i = 2; x * i <= n; i++) {
      if (n % (x * i) == 0) {
        v[x] = x * i;
        x *= i;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == -1)
      v[i] = i;
  }
  debug(v);
  for (int i = 1; i <= n; i++)
    cout << v[i] << " ";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  cout << fixed;
  SIEVE();
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
