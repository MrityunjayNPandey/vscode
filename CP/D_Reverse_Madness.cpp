/**
 *      codeforces: _joKer_0
 *      created: 26-09-2023 21:01:17
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
  cin >> n >> k;
  string str;
  cin >> str;
  m = k;
  map<int, map<int, int>> mpv;
  vector<int> v1(k);
  vector<int> v2(k);
  for (int i = 0; i < k; i++) {
    cin >> v1[i];
    v1[i]--;
  }
  for (int i = 0; i < k; i++) {
    cin >> v2[i];
    v2[i]--;
  }
  m = k;
  cin >> k;
  debug(v1);
  while (k--) {
    int x;
    cin >> x;
    x--;
    int ind = upper_bound(all(v1), x) - v1.begin() - 1;
    int l = v1[ind], r = v2[ind];
    int mid = (l + r) / 2;
    int diff = r - x;
    if (x > mid)
      x = l + diff;
    debug(x, ind);
    mpv[ind][x]++;
  }
  debug(str) debug(v1, v2, mpv);
  for (int i = 0; i < m; i++) {
    debug(i);
    int st = v1[i], en = v2[i];
    debug(st, en);
    int k = 0;
    for (int j = st; j <= (st + en) / 2; j++) {
      k += mpv[i][j];
      debug(k);
      if ((k & 1)) {
        debug(1);
        swap(str[j], str[en - (j - st)]);
      }
    }
  }
  cout << str;
}

sort(stock.begin(), stock.end());
return stock[k - 1];

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
