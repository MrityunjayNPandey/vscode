/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 24-11-2022 13:49:58
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
  int n = 0, m = 0, k = 1, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  set<int> ones, zeros;
  for (int i = 0; i < n; i++) {
    if (str[i] == '1')
      ones.insert(i);
    else
      zeros.insert(i);
  }
  debug(ones, zeros);
  vector<int> vans(n);
  int x;
  while (ones.size() || zeros.size()) {
    if (ones.empty()) {
      vans[*zeros.begin()] = k;
      k++;
      zeros.erase(zeros.begin());
    } else if (zeros.empty()) {
      vans[*ones.begin()] = k;
      k++;
      ones.erase(ones.begin());
    } else {
      if (cnt == 0) {
        if (*ones.begin() < *zeros.begin()) {
          vans[*ones.begin()] = k;
          x = *ones.begin();
          ones.erase(ones.begin());
        } else {
          vans[*zeros.begin()] = k;
          x = *zeros.begin();
          zeros.erase(zeros.begin());
          cnt++;
        }
      } else {
        if (cnt & 1) {
          auto it = zeros.lower_bound(x);
          if (it == zeros.end()) {
            k++;
            cnt = 0;
            continue;
          }
          vans[*it] = k;
          x = *it;
          zeros.erase(it);
        } else {
          auto it = ones.lower_bound(x);
          if (it == ones.end()) {
            k++;
            cnt = 0;
            continue;
          }
          vans[*it] = k;
          x = *it;
          ones.erase(it);
        }
      }
      debug(zeros, ones, x, k);
      cnt++;
    }
  }
  cout << --k << endl;
  for (auto i : vans)
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
