/**
 *      codeforces: _joKer_0
 *      created: 09-10-2023 21:00:35
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
  string str;
  cin >> str;
  cin >> k;
  debug(str, k);
  n = str.length();
  int x = n;
  while (x) {
    debug(x) sum += x;
    if (k <= sum) {
      break;
    }
    x--;
    cnt++;
  }
  debug(sum, cnt, x);
  stack<char> st;
  string strNew;
  for (int i = 0; i < n; i++) {
    while (cnt && st.size()) {
      if (st.top() > str[i])
        st.pop(), cnt--;
      else
        break;
    }
    st.push(str[i]);
  }
  while (st.size()) {
    strNew += st.top();
    st.pop();
  }
  reverse(all(strNew));
  debug(strNew);
  debug(sum, x, k) sum -= x;
  k -= sum;
  debug(k) cout << strNew[k - 1];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    // cout << endl;
  }
}
