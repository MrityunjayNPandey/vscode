/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 20-04-2023 21:53:12
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
  cin >> n >> k;
  vector<int> v(n), v1(n);
  for (auto &i : v)
    cin >> i;
  for (auto &i : v1)
    cin >> i;
  for (int i = 0; i < n; i++) {
    sum += v1[i] - v[i] + 1;
  }
  if (sum < k) {
    cout << -1 << endl;
    return;
  }
  sum = 0;
  int ind = 0;
  int step = 0;
  int st = 0, cost = 0;
  for (int i = 0; i < n; i++) {
    step += v[i] - st;
    st = v1[i];
    if (sum + v1[i] - v[i] + 1 >= k) {
      ind = i;
      break;
    }
    sum += v1[i] - v[i] + 1;
    cost += v1[i] - v[i] + 2;
  }
  if (k - sum > 0)
    cost += k - sum + 1 + step;
  else
    cost += step;
  for (int i = 0; i <= ind; i++) {
    if (v[i] == v1[i])
      cnt++;
  }
  if (sum + v1[ind] - v[ind] + 1 - k > 0) {
    cost -= min(sum + v1[ind] - v[ind] + 1 - k, cnt);
    cnt -= min(sum + v1[ind] - v[ind] + 1 - k, cnt);
  }
  int costf = cost;
  for (int i = ind + 1; i < n; i++) {
    int step = v[i] - v1[i - 1];
    cost += step;
    cost -= (min(v1[i] - v[i] + 1, cnt)) * 2;
    cost += (min(v1[i] - v[i] + 1, cnt)) + 1;
    costf = min(costf, cost);
    cnt -= min(v1[i] - v[i] + 1, cnt);
    if (v1[i] == v[i])
      cnt++;
  }
  cout << costf << endl;
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
  }
}
