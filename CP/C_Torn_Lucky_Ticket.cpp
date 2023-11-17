/**
 *      codeforces: _joKer_0
 *      created: 03-11-2023 20:32:23
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

bool compare(string &s1, string &s2) { return s1.size() < s2.size(); }

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<string> v(n);
  for (auto &i : v)
    cin >> i;
  sort(all(v), compare);
  debug(v);
  map<int, map<int, int>> mp;
  for (int i = 0; i < n; i++) {
    ans++;
    int tSum = 0;
    for (int j = 0; j < v[i].length(); j++) {
      tSum += v[i][j] - '0';
    }
    sum = 0;
    int sz = v[i].length();
    k = 0;
    for (int j = 0; j < v[i].length(); j++) {
      sum += v[i][j] - '0';
      k++;
      if (mp.contains(sum - (tSum - sum))) {
        if (mp[sum - (tSum - sum)].contains(k - (sz - k)))
          ans += mp[sum - (tSum - sum)][k - (sz - k)];
      }
    }
    sum = 0;
    k = 0;
    for (int j = v[i].length() - 1; j >= 0; j--) {
      k++;
      sum += v[i][j] - '0';
      if (mp.contains(sum - (tSum - sum))) {
        if (mp[sum - (tSum - sum)].contains(k - (sz - k)))
          ans += mp[sum - (tSum - sum)][k - (sz - k)];
      }
    }
    mp[sum][v[i].length()]++;
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
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}