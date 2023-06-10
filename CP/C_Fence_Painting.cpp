/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 11-06-2023 02:12:22
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
  cin >> n >> m;
  vector<int> v1(n), v2(n);
  for (auto &i : v1)
    cin >> i;
  for (auto &i : v2)
    cin >> i;
  map<int, vector<int>> sat, unsat;
  vector<int> vans;
  for (int i = 0; i < n; i++) {
    if (v1[i] == v2[i]) {
      sat[v2[i]].pb(i);
    } else {
      unsat[v2[i]].pb(i);
    }
  }
  debug(sat, unsat);
  vector<int> vm(m);
  for (int i = 0; i < m; i++) {
    cin >> vm[i];
  }
  debug(vm) for (int i = 0; i < m; i++) {
    int x;
    x = vm[i];
    debug(x, unsat, sat) if (unsat.contains(x)) {
      sat[x].pb(unsat[x].back());
      vans.pb(unsat[x].back());
      unsat[x].pop_back();
      if (unsat[x].empty()) {
        unsat.erase(x);
      }
    }
    else if (sat.contains(x)) {
      vans.pb(sat[x].back());
    }
    else if (unsat.size()) {
      vans.pb(((*unsat.begin()).second).back());
    }
    else {
      debug(unsat, sat);
      int col = -1;
      map<int, int> freq;
      for (int j = i + 1; j < m; j++) {
        freq[vm[j]]++;
      }
      debug(freq);
      for (auto &[l, r] : sat) {
        k = 0;
        if (unsat.contains(l)) {
          k = unsat[l].size();
        }
        if (freq[l] > k) {
          col = l;
          break;
        }
      }
      if (col == -1) {
        cout << "NO";
        return;
      } else {
        vans.pb(sat[col].back());
        unsat[col].pb(sat[col].back());
        sat[col].pop_back();
      }
    }
  }
  debug(sat, unsat);
  if (unsat.size()) {
    cout << "NO";
    return;
  }
  cout << "YES" << endl;
  for (auto &i : vans)
    cout << i + 1 << " ";
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
