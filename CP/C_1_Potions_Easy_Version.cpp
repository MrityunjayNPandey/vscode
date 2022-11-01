/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 01-11-2022 22:45:20
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

int n;
// int func(int i, int sum, vector<int> &v, vector<map<int, int>> &dp) {
//   if (i == n)
//     return 0;
//   if (dp[i].count(sum))
//     return dp[i][sum];
//   int choose = 0, nchoose = 0;
//   if (v[i] >= 0) {
//     choose = func(i + 1, sum + v[i], v, dp) + 1;
//   } else {
//     if (sum + v[i] >= 0) {
//       choose = func(i + 1, sum + v[i], v, dp) + 1;
//       nchoose = func(i + 1, sum, v, dp);
//     } else
//       nchoose = func(i + 1, sum, v, dp);
//   }
//   return dp[i][sum] = max(choose, nchoose);
// }

void showpq(priority_queue<int, vector<int>, greater<int> > gq) {
  priority_queue<int, vector<int>, greater<int> > g = gq;
  while (!g.empty()) {
    clog << g.top();
    g.pop();
  }
  clog << '\n';
}

void solve() {
  int m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n), v1;
  vector<map<int, int>> dp(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  priority_queue<int, vector<int>, greater<int> > q;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    if (v[i] < 0)
      q.push(v[i]);
    else
      ans++;
    debug(sum);
    if (sum < 0) {
      sum -= q.top();
      q.pop();
    }
    debug(sum);
    // showpq(q);
  }
  ans += q.size();
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  // cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
