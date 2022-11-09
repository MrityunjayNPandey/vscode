/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 07-11-2022 13:58:37
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
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for (auto &i : v) {
    cin >> i;
    mp[i]++;
  }
  multiset<int> mltst;
  for (auto i : mp) {
    mltst.insert(i.second);
  }
  debug(mp, mltst);
  cin >> m;
  while (m--) {
    char x;
    int p1;
    cin >> x >> p1;
    if (x == '+') {
      int px = *mltst.lower_bound(mp[p1]);
      if (px == mp[p1])
        mltst.erase(mltst.lower_bound(mp[p1]));
      mp[p1]++;
      mltst.insert(mp[p1]);
    } else {
      mltst.erase(mltst.lower_bound(mp[p1]));
      mp[p1]--;
      mltst.insert(mp[p1]);
    }
    debug(mltst, mp, p1);
    if (mltst.size() == 0) {
      cout << "NO";
      continue;
    }
    if (*mltst.rbegin() >= 8) {
      cout << "YES\n";
    } else {
      if (mltst.size() == 1) {
        cout << "NO\n";
        continue;
      }
      if (mltst.size() >= 3) {
        int p = *mltst.rbegin();
        mltst.erase(prev(mltst.end()));
        int q = *mltst.rbegin();
        mltst.erase(prev(mltst.end()));
        int r = *mltst.rbegin();
        mltst.insert(p);
        mltst.insert(q);
        if (p + q + r < 8) {
          cout << "NO\n";
          continue;
        } else {
          if ((p >= 4 && q >= 2 && r >= 2)) {
            cout << "YES\n";
            continue;
          }
        }
      }
      int p = *mltst.rbegin();
      mltst.erase(prev(mltst.end()));
      int q = *mltst.rbegin();
      mltst.insert(p);
      if (p + q < 8) {
        cout << "NO\n";
      } else {
        if (min(p, q) >= 2 && max(p, q) >= 6 || (p >= 4 && q >= 4)) {
          cout << "YES\n";
        } else
          cout << "NO\n";
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      Test = 1;
  //   cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}