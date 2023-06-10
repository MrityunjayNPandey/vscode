/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-06-2023 15:32:35
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
  cin >> n;
  vector<int> v1(n), v2(n);
  for (auto &i : v1)
    cin >> i;
  for (auto &i : v2)
    cin >> i;
  vector<int> vn(n), vr(n);
  for (int i = 0; i < n; i++) {
    vn[i] = v1[i] * v2[i];
  }
  for (int i = 1; i < n; i++) {
    vn[i] += vn[i - 1];
  }
  ans = vn[n - 1];
  for (int i = 0; i < n; i++) {
    int x = v1[i] * v2[i];
    ans = max(ans, ((i == 0) ? 0 : vn[i - 1]) + x + vn[n - 1] - vn[i]);
    for (int l = i - 1, r = i + 1; l >= 0 && r < n; l--, r++) {
      x += v1[l] * v2[r] + v1[r] * v2[l];
      ans = max(ans, ((l == 0) ? 0 : vn[l - 1]) + x + vn[n - 1] - vn[r]);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int x = v1[i] * v2[i + 1] + v1[i + 1] * v2[i];
    ans = max(ans, ((i == 0) ? 0 : vn[i - 1]) + x + vn[n - 1] - vn[i + 1]);
    for (int l = i - 1, r = i + 2; l >= 0 && r < n; l--, r++) {
      x += v1[l] * v2[r] + v1[r] * v2[l];
      ans = max(ans, ((l == 0) ? 0 : vn[l - 1]) + x + vn[n - 1] - vn[r]);
    }
  }
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
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
