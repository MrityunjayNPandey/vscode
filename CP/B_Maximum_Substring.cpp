/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-11-2022 20:14:16
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
  string str;
  cin >> str;
  vector<int> zero(n), one(n);
  int noon = 0, nozr = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0')
      zero[i] = 1, nozr++;
    else
      one[i] = 1, noon++;
  }
  vector<int> zer, on;
  for (int i = 0; i < n; i++) {
    if (zero[i] == 1) {
      cnt++;
    } else {
      if (cnt) {
        zer.pb(cnt);
      }
      cnt = 0;
    }
  }
  if (cnt)
    zer.pb(cnt);
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (one[i] == 1) {
      cnt++;
    } else {
      if (cnt) {
        on.pb(cnt);
      }
      cnt = 0;
    }
  }
  if (cnt)
    on.pb(cnt);
  debug(zer, on);
  sort(all(zer));
  sort(all(on));
  int mx1 = 0, mx2 = 0;
  if (zer.size())
    mx1 = zer[zer.size() - 1];
  if (on.size())
    mx2 = on[on.size() - 1];
  int mx = max(mx1, mx2);
  debug(mx);
  cout << max(noon * nozr, mx*mx);
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
