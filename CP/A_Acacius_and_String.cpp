/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-11-2022 03:51:36
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str, strm = "abacaba";
  cin >> str;
  debug(str);
  for (int i1 = 0; i1 <= n - 7; i1++) {
    string strt = "";
    for (int j1 = i1; j1 < i1 + 7; j1++)
      strt += str[j1];
    if (strt == strm)
      cnt++;
  }
  if (cnt == 1) {
    cout << "Yes" << endl;
    for (int it = 0; it < str.length(); it++) {
      if (str[it] == '?') {
        cout << "f";
      } else
        cout << str[it];
    }
    return;
  }
  cnt = 0;
  for (int i = 0; i <= n - 7; i++) {
    debug(i);
    string strtmp = str, strt;
    int flag = 0;
    for (int j = i; j < i + 7; j++)
      strt += str[j];
    debug(strt);
    for (int j = 0; j < 7; j++) {
      if (strt[j] != '?' && strt[j] != strm[j]) {
        flag++;
        break;
      }
    }
    debug(flag);
    cnt = 0;
    if (!flag) {
      k = 0;
      for (int j = i; j < i + 7; j++)
        strtmp[j] = strm[k++];
      debug(strtmp);
      for (int i1 = 0; i1 <= n - 7; i1++) {
        string strt = "";
        for (int j1 = i1; j1 < i1 + 7; j1++)
          strt += strtmp[j1];
        if (strt == strm)
          cnt++;
      }
      debug(cnt);
      if (cnt == 1) {
        cout << "Yes" << endl;
        for (int it = 0; it < strtmp.length(); it++) {
          if (strtmp[it] == '?') {
            cout << "f";
          } else
            cout << strtmp[it];
        }
        return;
      }
    }
  }
  cout << "No";
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
