/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 04-04-2023 21:21:17
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

// O(log(n)), representing powers in binary form.
int bin_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) {
      (res *= a);
    }
    p >>= 1;
    (a *= a);
  }
  return res;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, sum = 0;
  string str;
  cin >> str;
  n = stoll(str);
  vector<int> v = {0, 1, 2, 3, 5, 6, 7, 8, 9};
  int l = n, r = 1e13;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    ans = 0;
    str = to_string(mid);
    debug(l, mid, r);
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
      int ind = lower_bound(all(v), str[i] - '0') - v.begin();
      if (str[i] == '4' && str.length() != 1) {
        cnt++;
        if (i == str.length() - 1) {
          ans += 4;
        } else {
          ind = 4;
          ans += ind * (bin_pow(9, str.length() - i - 1));
        }
        break;
      }
      if (i == str.length() - 1) {
        ans += ind + 1;
        break;
      }
      ans += ind * (bin_pow(9, str.length() - i - 1));
      debug(ans, str.length() - i - 1);
    }
    if (ans - 1 == n && !cnt) {
      cout << mid;
      return;
    }
    if (ans - 1 < n) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
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
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
