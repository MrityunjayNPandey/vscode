/**
 *      codeforces: _joKer_0
 *      created: 28-10-2023 20:46:50
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  vector<int> vans;
  int l = 0, r = n;
  while (str.length()) {
    string strn;
    if (str[0] == str[str.length() - 1]) {
      if (str[0] == '1') {
        strn += '1';
        for (int i = 0; i < str.length() - 1; i++) {
          strn += str[i];
        }
        if (strn == str) {
          cout << -1;
          return;
        }
        vans.pb(l);
      } else {
        for (int i = 1; i < str.length(); i++) {
          strn += str[i];
        }
        strn += '0';
        if (strn == str) {
          cout << -1;
          return;
        }
        vans.pb(r);
      }
      r += 1;
      l += 1;
    } else {
      for (int i = 1; i < str.length() - 1; i++) {
        strn += str[i];
      }
      l++, r--;
    }
    str = strn;
  }
  cout << vans.size() << endl;
  for (auto &i : vans)
    cout << i << " ";
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
