/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 31-10-2022 16:06:27
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

void solve() {
  int n = 0, m = 0, k = 0, q = 0, ans = 0, cnt = 0, sum = 0;
  //   cin >> n;
  string str;
  cin >> str;
  string str1 = str;
  debug(str);
  // ans += str.length();
  n = str.length();
  int idx = 0, idx1 = n - 1;
  int r = n - 1, l = n - 1;
  int ind = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] != '?') {
      ind = i;
      break;
    }
  }
  if (ind == 0) {
    cout << n * (n + 1) / 2 << endl;
    return;
  }
  debug(ind);
  char last = '?';
  int lstqind = r;
  set<pair<int, int>> st;
  l = ind;
  for (int i = ind - 1; i >= 0; i--) {
    if (str[i] == '?' && (last != '?' || i == ind - 1))
      lstqind = i;
    if ((ind - i) % 2) {
      if (str[i] != str[ind] || str[i] == '?') {
        l = i;
      } else {
        if (r >= l)
          st.insert({l, r});
        if (str[i + 1] == '?')
          r = lstqind, l = i;
        else {
          r = i;
        }
        l = min(l, r);
        ind = i;
      }
    } else {
      if (str[i] == str[ind] || str[i] == '?')
        l = i;
      else {
        if (r >= l)
          st.insert({l, r});
        if (str[i + 1] == '?') {
          r = lstqind;
          l = i;
        } else {
          r = i;
        }
        ind = i;
        l = min(l, r);
      }
    }
    last = str[i];
  }
  if (r >= l)
    st.insert({l, r});
  int srt, nd;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    if (str[i] == '?' && !cnt)
      srt = i, cnt++;
    if (str[i] != '?' && cnt) {
      nd = i - 1;
      vp.pb({srt, nd});
      cnt = 0;
    }
  }
  if (str[n - 1] == '?')
    vp.pb({srt, nd});
  debug(vp);
  debug(ans);
  for (auto i : st) {
    int x = i.second - i.first;
    ans += (x + 1) * (x + 2) / 2;
  }
  debug(ans, sum);
  int lb = (*st.begin()).second;
  auto it1 = ++st.begin();
  for (auto it = it1; it != st.end(); it++) {
    int ub = (*it).first;
    if (ub <= lb) {
      sum += (lb - ub + 1) * (lb - ub + 2) / 2;
    }
    lb = (*it).second;
  }
  debug(sum);
  debug(st);
  cout << ans - sum;
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
