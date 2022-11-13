/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-11-2022 21:50:09
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  if (str1 == str2 && str1.find('1') == string::npos) {
    cout << "YES" << endl << 0 << endl;
    return;
  } else {
    int xorr;
    if (str1[0] == str2[0])
      xorr = 0;
    else
      xorr = 1;
    debug(str1, str2);
    debug(xorr);
    for (int i = 1; i < n; i++) {
      if (str1[i] == str2[i]) {
        if (xorr) {
          cout << "NO" << endl;
          return;
        }
      } else {
        if (xorr == 0) {
          cout << "NO" << endl;
          return;
        }
      }
    }
    cout << "YES" << endl;
    int no1 = 0, no0 = 0;
    for (int i = 0; i < n; i++) {
      if (str1[i] == '1')
        no1++;
      else
        no0++;
    }
    if (n == 2) {
      if (str1 == "10" && str1 == str2) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << 2 << endl;
        return;
      }
      if (str1 == "10" && str2 == "01") {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return;
      }
      if (str1 == "01" && str2 == "10") {
        cout << 1 << endl;
        cout << 2 << " " << 2 << endl;
        return;
      }
      if (str1 == "01" && str1 == str2) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return;
      }
      if (str1 == "11" && str2 == "00") {
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
      }
      if (str1 == "00" && str2 == "11") {
        cout << 3 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
      }
    }
    if ((no1 != 0 && no1 < n) || (no1 == n && count(all(str2), '1')==0)) {
      if (count(all(str1), '1') == 1 && count(all(str2), '1') == n - 1) {
        if (str1[str1.find('1')] == '1' && str2[str1.find('1')] == '0') {
          cout << 1 << endl;
          cout << str1.find('1') + 1 << " " << str1.find('1') + 1 << endl;
          return;
        }
      }
      if (no1 % 2 && str1 != str2)
        cout << no1 << endl;
      else
        cout << no1 + 5 << endl;
      for (int i = 0; i < n; i++) {
        if (str1[i] == '1') {
          cout << i + 1 << " " << i + 1 << endl;
        }
      }
      if (no1 % 2 && str1 != str2)
        return;
      cout << 2 << " " << max(n - 1, 2LL) << endl;
      cout << 1 << " " << 1 << endl;
      cout << n << " " << n << endl;
      cout << 1 << " " << max(n - 1, 1LL) << endl;
      cout << n << " " << n << endl;
    } else if (no1 == 0) {
      cout << 5 << endl;
      cout << 2 << " " << max(n - 1, 2LL) << endl;
      cout << 1 << " " << 1 << endl;
      cout << n << " " << n << endl;
      cout << 1 << " " << max(n - 1, 1LL) << endl;
      cout << n << " " << n << endl;
    } else {
      cout << 2 << endl;
      cout << n << " " << n << endl;
      cout << 1 << " " << n - 1 << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
