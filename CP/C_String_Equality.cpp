/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-11-2022 01:46:46
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
  cin >> n >> k;
  string str1, str2;
  cin >> str1 >> str2;
  map<char, int> mp1, mp2;
  for (int i = 0; i < n; i++)
    mp1[str1[i]]++, mp2[str2[i]]++;
  vector<char> v1;
  for (auto &i : mp2) {
    if (mp1.count(i.first)) {
      int p = min(mp1[i.first], i.second);
      mp1[i.first] -= p;
      if (mp1[i.first] == 0)
        mp1.erase(i.first);
      i.second -= p;
      if (i.second == 0)
        v1.pb(i.first);
    }
  }
  for (auto i : v1)
    mp2.erase(i);
  debug(mp1, mp2);
  if (mp1.size() && mp2.size())
    while ((*mp1.begin()).second >= k && (*mp2.begin()).second >= k &&
           (*mp1.begin()).first <= (*mp2.begin()).first) {
      int fi1 = (*mp1.begin()).first;
      int fi2 = (*mp2.begin()).first;
      mp1[fi1] -= k;
      mp2[fi2] -= k;
      if (mp1[fi1] == 0)
        mp1.erase(fi1);
      if (mp2[fi2] == 0)
        mp2.erase(fi2);
      debug(mp1, mp2);
      if (mp1.empty() || mp2.empty())
        break;
    }
  if (mp1.size() || mp2.size())
    cout << "No";
  else
    cout << "Yes";
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
    cout << endl;
  }
}
