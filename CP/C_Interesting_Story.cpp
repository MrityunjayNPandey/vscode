/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 09-11-2022 19:41:41
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
  vector<int> va, vb, vc, vd, ve;
  m = n;
  while (m--) {
    string str;
    cin >> str;
    int sz = str.length();
    map<char, int> mp;
    for (int i = 0; i < str.length(); i++) {
      mp[str[i]]++;
    }
    va.pb(2 * mp['a'] - sz);
    vb.pb(2 * mp['b'] - sz);
    vc.pb(2 * mp['c'] - sz);
    vd.pb(2 * mp['d'] - sz);
    ve.pb(2 * mp['e'] - sz);
    // debug(va, vb, vc, vd, ve)
  }
  sort(rall(va));
  sort(rall(vb));
  sort(rall(vc));
  sort(rall(vd));
  sort(rall(ve));
  debug(va, vb, vc, vd, ve);
  for (int i = 0; i < n; i++) {
    if (sum + va[i] > 0)
      sum += va[i];
    else {
      ans = max(ans, i);
      cnt++;
      break;
    }
    debug(sum);
  }
  if (!cnt)
    ans = max(ans, n);
  debug(ans);
  sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum + vb[i] > 0)
      sum += vb[i];
    else {
      ans = max(ans, i);
      cnt++;
      break;
    }
  }
  if (!cnt)
    ans = max(ans, n);
  sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum + vc[i] > 0)
      sum += vc[i];
    else {
      ans = max(ans, i);
      cnt++;
      break;
    }
  }
  if (!cnt)
    ans = max(ans, n);
  sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum + vd[i] > 0)
      sum += vd[i];
    else {
      ans = max(ans, i);
      cnt++;
      break;
    }
  }
  if (!cnt)
    ans = max(ans, n);
  sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (sum + ve[i] > 0)
      sum += ve[i];
    else {
      ans = max(ans, i);
      cnt++;
      break;
    }
  }
  if (!cnt)
    ans = max(ans, n);
  cout << ans;
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
