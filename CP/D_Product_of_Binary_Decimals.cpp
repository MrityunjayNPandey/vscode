/**
 *      codeforces: _joKer_0
 *      created: 28-03-2024 20:57:10
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

string DecimalToBinary(int num) {
  string str;
  while (num) {
    if (num & 1) // 1
      str += '1';
    else // 0
      str += '0';
    num >>= 1; // Right Shift by 1
  }
  return str;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  int num;
  cin >> num;
  vector<int> v;
  for (int i = 32; i > 1; i--) {
    string str = DecimalToBinary(i);
    reverse(all(str));
    v.pb(stoi(str));
  }
  debug(v);

  while (num > 1) {
    int x = num;
    debug(x);
    for (int i = 0; i < v.size(); i++) {
      if (x % v[i] == 0) {
        x /= v[i];
        break;
      }
    }
    debug(x);
    if (x == num) {
      cout << "NO";
      return;
    }
    num = x;
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
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
