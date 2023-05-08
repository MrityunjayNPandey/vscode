/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-05-2023 18:24:13
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
  cin >> n >> m;
  vector<int> v(n), ind;
  map<int, int> mp;
  set<int> st;
  for (auto &i : v) {
    cin >> i;
    if (i != -1 && i != -2) {
      st.insert(i - 1);
    } else {
      mp[i]++;
    }
  }
  for (auto i : st)
    ind.pb(i);
  // case 1 when no x is chosen:

  //-1
  int p = mp[-1];
  int anst = 0, anst1 = 0;
  for (int i = 0; i < m; i++) {
    if (p) {
      anst++;
      if (st.find(i) != st.end()) {
        continue;
      }
      p--;
    }
  }

  //-2
  int q = mp[-2];
  for (int i = m - 1; i >= 0; i--) {
    if (q) {
      anst1++;
      if (st.find(i) != st.end()) {
        continue;
      }
      q--;
    }
  }

  ans = max(anst, anst1);

  // when some x is chosen;
  for (int i = 0; i < ind.size(); i++) {
    int temp = ind.size();
    temp += min(m - ind[i] - 1 - ((int)ind.size() - i - 1), mp[-2]);
    temp += min(ind[i] - i, mp[-1]);
    ans = max(temp, ans);
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
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
