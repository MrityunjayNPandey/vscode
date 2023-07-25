/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 25-07-2023 21:17:41
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
  vector<int> v(n - 1);
  for (auto &i : v)
    cin >> i;
  debug(v);
  multiset<int> diff;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.insert(i);
  }
  diff.insert(v[0]);
  st.erase(v[0]);
  for (int i = 1; i < n - 1; i++) {
    diff.insert(v[i] - v[i - 1]);
    st.erase(v[i] - v[i - 1]);
  }
  debug(diff, st);
  if (st.size() == 1) {
    cout << "YES";
    return;
  }
  if (st.size() != 2) {
    cout << "NO";
    return;
  }
  if (!diff.contains(*st.begin() + *st.rbegin())) {
    cout << "NO";
    return;
  } else {
    diff.erase(diff.find(*st.begin() + *st.rbegin()));
    diff.insert(*st.begin());
    diff.insert(*st.rbegin());
  }
  k = 1;
  for (auto &i : diff) {
    if (i != k) {
      cout << "NO";
      return;
    }
    k++;
  }
  cout << "YES";
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
