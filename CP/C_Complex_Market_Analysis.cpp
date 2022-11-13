/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-10-2022 13:48:46
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

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primetemp(MAX_N + 1, 1), ifprime(MAX_N + 1, 0), prime;
void SIEVE() {
  prime.pb(1);
  //   ifprime[1]++;
  for (int p = 2; p <= MAX_N; p++) {
    if (primetemp[p] == 1) {
      prime.pb(p);
      ifprime[p]++;
      for (int i = p * p; i <= MAX_N; i += p) {
        primetemp[i] = 0;
      }
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n), v1;
  set<int> st;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    if (ifprime[v[i]]) {
      v1.pb(i);
    }
    if (v[i] == 1) {
      st.insert(i);
    }
  }
  debug(v1, st) for (auto i : v1) {
    int m1 = 1, p1 = 0, p2 = 0;
    while (st.find(i + m1 * k) != st.end() && i + m1 * k < n) {
      debug(i, i + m1 * k)
      m1++;
      p1++;
    }
    int m2 = 1;
    while (st.find(i - m2 * k) != st.end() && i - m2 * k >= 0) {
      debug(i, i - m2 * k)
      m2++;
      p2++;
    }
    m1--, m2--;
     if (p1 && p2) { ans += m2 * (m1 + 1) + m1; }
    else if (p1 || p2) {
      ans += (p1) ? m1 : m2;
    }
    debug(ans)
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  SIEVE();
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
