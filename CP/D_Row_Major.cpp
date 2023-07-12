/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 11-07-2023 21:43:21
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

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> isprime(MAX_N + 1, 1), prime;
void SIEVE() {
  for (int p = 2; p <= MAX_N; p++) {
    if (isprime[p]) {
      prime.emplace_back(p);
      for (int i = p * p; i <= MAX_N; i += p) {
        isprime[i] = 0;
      }
    }
  }
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  set<int> fact;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      fact.insert(i);
      fact.insert(n / i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!fact.contains(i)) {
      ans = i;
      break;
    }
  }
  if (!ans)
    ans = n + 1;
  debug(ans);
  string str = "";
  for (char i = 'a'; i < 'a' + ans; i++)
    str += i;

  for (int i = 0; i < n / ans; i++) {
    cout << str;
  }
  for (int i = 0; i < n % ans; i++) {
    cout << str[i];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
  SIEVE();
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
