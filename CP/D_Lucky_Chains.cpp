/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-05-2023 04:20:45
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
const long long MAX_N = 1e7 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

vector<int> minfact(1e7 + 8, 0);

vector<int> primetemp(MAX_N + 1, 1), isprime(MAX_N + 1, 0), prime;
void SIEVE() {
  prime.pb(1);
  isprime[1]++;
  for (int p = 2; p <= MAX_N; p++) {
    if (primetemp[p] == 1) {
      prime.pb(p);
      isprime[p]++;
      for (int i = p; i <= MAX_N; i += p) {
        primetemp[i] = 0;
        minfact[i] = p;
      }
    }
  }
  debug(minfact[2])
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> m;
  if (__gcd(n, m) > 1) {
    cout << 0<<endl;
    return;
  }
  if ((n & 1) && (m & 1)) {
    cout << 1 << endl;
    return;
  }
  int diff = m - n;
  if (diff == 1) {
    cout << -1 << endl;
    return;
  }
  vector<int> fact;
  fact.pb(diff);
  while (diff > 1) {
    debug(diff);
    fact.pb(minfact[diff]);
    diff /= minfact[diff];
  }
  debug(fact);
  ans = INF;
  for (auto i : fact) {
    int p = ((n - 1) / i + 1) * i;
    ans = min(ans, p - n);
  }
  cout << ans << endl;
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
  SIEVE();
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
