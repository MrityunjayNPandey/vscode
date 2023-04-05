/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 28-02-2023 20:28:12
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

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  string str1, str2;
  cin >> str1 >> str2;
  debug(str1, str2);
  set<string> st;
  n = str1.length();
  m = str2.length();
  for (int i = 0; i < n - 1; i++) {
    string str;
    str += str1[i];
    str += str1[i + 1];
    st.insert(str);
  }
  debug(st);
  for (int i = 0; i < m - 1; i++) {
    string str;
    str += str2[i];
    str += str2[i + 1];
    if (st.find(str) != st.end()) {
      cout << "YES\n";
      cout << "*" << str << "*";
      return;
    }
  }
  if (str1[0] == str2[0]) {
    cout << "YES\n";
    cout << str1[0] << "*";
    return;
  }
  if (str1[str1.length() - 1] == str2[str2.length() - 1]) {
    cout << "YES\n";
    cout << "*" << str1[str1.length() - 1];
    return;
  }
  cout << "NO";
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
