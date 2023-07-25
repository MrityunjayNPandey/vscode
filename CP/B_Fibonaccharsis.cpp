/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 23-07-2023 20:36:23
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

void multiply(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

// Function that returns nth Fibonacci number
int fib(int n) {
  int F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0)
    return 0;
  power(F, n - 1);

  return F[0][0];
}

// Optimized version of power() in method 4
void power(int F[2][2], int n) {
  if (n == 0 || n == 1)
    return;
  int M[2][2] = {{1, 1}, {1, 0}};

  power(F, n / 2);
  multiply(F, F);

  if (n % 2 != 0)
    multiply(F, M);
}

void multiply(int F[2][2], int M[2][2]) {
  int x = (F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD;
  int y = (F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD;
  int z = (F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD;
  int w = (F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  int a = fib(k - 2), b = fib(k - 1);
  debug(-5%5)
  debug(a, b);
  for (int x = 0; x < n; x++) {
    if ((n - x * a) % b == 0) {
      if ((n - x * a) / b < x)
        break;
      cnt++;
    }
  }
  cout << cnt;
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
