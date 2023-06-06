/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-06-2023 15:19:06
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
  cin >> n >> k;
  string str;
  cin >> str;
  vector<int> vind;
  int ind = INF;
  for (int i = 0; i < n; i++) {
    if (str[i] > str[0]) {
      ind = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (str[i] == str[0]) {
      vind.pb(i);
    }
  }
  for (auto &i : vind) {
    cnt = 0;
    while (cnt < i && i + cnt < n) {
      if (str[cnt] < str[i + cnt]) {
        ind = min(ind, i);
        break;
      } else if (str[cnt] > str[i + cnt])
        break;
      cnt++;
    }
  }
  if (ind == INF) {
    for (int i = n - 1; i >= 1; i--) {
      if (str[i] == str[0])
        ind = i;
      else
        break;
    }
  }
  debug(ind);
  if (ind == INF) {
    for (int i = 0; i < k / n; i++)
      cout << str;
    for (int i = 0; i < k % n; i++)
      cout << str[i];
  } else {
    string str1;
    for (int i = 0; i < ind; i++)
      str1 += str[i];
    n = str1.size();
    for (int i = 0; i < k / n; i++)
      cout << str1;
    for (int i = 0; i < k % n; i++)
      cout << str1[i];
  }
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
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
