/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 18-07-2023 02:50:19
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
  vector<pair<int, int>> vp(n);
  for (auto &[l, r] : vp) {
    cin >> r >> l;
  }
  sort(all(vp));
  debug(vp) vector<int> pref(n);
  for (auto &[r, l] : vp) {
    sum += l;
  }
  int l = 0, r = sum;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    debug(mid);
    int sumt = 0;
    int ind = 0, mx = 0;
    cnt = sum - mid;
    bool flag1 = true;
    for (int i = 0; i < n; i++) {
      if (sumt + vp[i].second > mid) {
        ind = i;
        break;
      }
      if (vp[i].first > cnt) {
        flag1 = false;
        break;
      }
      cnt += vp[i].second;
      sumt += vp[i].second;
    }
    bool flag = false;
    if (sumt != mid && flag1) {
      if (vp[ind].first <= cnt)
        flag = true;
    }
    debug(sumt, cnt, vp[ind].first);
    if (flag || sumt == mid) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  debug(ans);
  cout << ans + (sum - ans) * 2;
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
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
