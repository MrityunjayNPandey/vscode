/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 07-06-2023 02:47:44
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
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }
  vector<int> vans(n);
  for (int i = 0; i < n; i++) {
    if (st.contains(v[i])) {
      vans[i] = v[i];
      st.erase(v[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (vans[i] == 0) {
      vans[i] = *st.begin();
      st.erase(vans[i]);
    }
  }
  vector<int> self;
  map<int, int> unequal, equal;
  for (int i = 0; i < n; i++) {
    if (v[i] == vans[i])
      equal[v[i]] = i;
    else if (vans[i] != i + 1) {
      unequal[vans[i]] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vans[i] == i + 1)
      self.pb(i);
  }
  debug(v, vans, self, equal, unequal);
  if (((int)self.size() & 1) == 0) {
    for (int i = 0; i < self.size(); i += 2) {
      if (i + 1 == self.size())
        break;
      swap(vans[self[i]], vans[self[i + 1]]);
    }
  } else {
    if (unequal.size()) {
      for (int i = 0; i < self.size(); i += 2) {
        if (i + 1 == self.size())
          break;
        swap(vans[self[i]], vans[self[i + 1]]);
      }
      swap(vans[self[self.size() - 1]], vans[(*unequal.begin()).second]);
    } else {
      int ind = (*equal.begin()).second;
      for (int i = 0; i < self.size(); i++) {
        if (equal.contains(v[self[i]])) {
          ind = equal[v[self[i]]];
          swap(self[i], self[self.size() - 1]);
          break;
        }
      }
      for (int i = 0; i < self.size(); i += 2) {
        if (i + 1 == self.size())
          break;
        swap(vans[self[i]], vans[self[i + 1]]);
      }
      swap(vans[self[self.size() - 1]], vans[ind]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == vans[i])
      ans++;
  }
  cout << ans << endl;
  for (auto &i : vans)
    cout << i << " ";
  cout << endl;
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
