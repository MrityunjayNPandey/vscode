/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-12-2022 22:01:39
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

//Gaand faad Problem
//Chinese Remainder theorum aur pigeonhole principle ka chod

// Sieve of Eratosthenes, time complexity of O(N*log(logN))
vector<int> primetemp(MAX_N + 1, 1), isprime(MAX_N + 1, 0), prime;
void SIEVE() {
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
  cin >> n;
  vector<int> v(n);
  int noo = 0, noe = 0;
  map<int, int> mp;
  for (auto &i : v) {
    cin >> i;
    if (i & 1) {
      noo++;
    } else {
      noe++;
    }
    if (mp.count(i))
      ans++;
    mp[i]++;
  }
  if ((noo >= 2 && noe >= 2) || ans) {
    cout << "NO";
    return;
  }
  for (int i = 0; prime[i] <= n; i++) {
    vector<int> vt(prime[i]);
    for (int j = 0; j < n; j++) {
      vt[v[j] % prime[i]]++;
    }
    if (*min_element(all(vt)) > 1) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  SIEVE();
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
