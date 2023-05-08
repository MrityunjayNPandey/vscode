/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-05-2023 22:03:52
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
      (res *= a) %= MOD;
    }
    p >>= 1;
    (a *= a) %= MOD;
  }
  return res;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  map<int, multiset<int>> mp;
  for (int i = 0; i < n; i++) {
    int k1 = 5;
    while (k1 >= 0) {
      if (v[i] & (1 << k1)) {
        mp[k1].insert(v[i]);
      }
      k1--;
    }
  }
  debug(mp);
  string str = "000000";
  vector<int> check = {0, 0, 0, 0, 0, 0};
  debug(k);
  for (int i = 5; i >= 6 - k; i--) {
    check[i] = 1;
  }
  string str1 = str;
  do {
    debug(check);
    multiset<int> mltst;
    for (int i = 5; i >= 0; i--) {
      if (check[i] == 1) {
        mltst = mp[5 - i];
        break;
      }
    }
    for (int i = 0; i < 6; i++) {
      if (check[i] == 1) {
        vector<int> temp;
        for (auto j : mltst) {
          if ((j & (1 << (5 - i))) == 0) {
            temp.pb(j);
          }
        }
        for (auto k : temp) {
          mltst.erase(mltst.find(k));
        }
      }
    }
    if (k == 0) {
      for (auto i : v)
        mltst.insert(i);
    }
    debug(mltst);
    vector<vector<int>> dp(mltst.size() + 1, vector<int>(1 << 6, 0));
    vector<int> v1(1);
    for (auto i : mltst) {
      v1.pb(i);
    }
    for (int i = 1; i <= mltst.size(); i++) {
      for (int mask = 0; mask < (1 << 6); ++mask) {
        (dp[i][mask] += dp[i - 1][mask]) %= MOD;
        (dp[i][mask & v1[i]] += dp[i - 1][mask]) %= MOD;
      }
      dp[i][v1[i]] = (dp[i][v1[i]] + 1) % MOD;
    }
    int num = 0;
    for (int i = 5; i >= 0; i--) {
      if (check[i])
        num += bin_pow(2, 5 - i);
    }
    (ans += dp[mltst.size()][num]) %= MOD;
  } while (next_permutation(all(check)));
  cout << ans;
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
