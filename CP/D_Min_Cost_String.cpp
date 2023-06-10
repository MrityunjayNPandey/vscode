/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-06-2023 23:13:11
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
  debug(n, k);
  string str = "a";
  if (n == 1) {
    cout << str;
    return;
  }
  // DFS, time complexity of O(V+E)
  // Euclidian Cycle
  map<char, bool> visited;
  map<char, vector<char>> adj_list; // adjacency list
  function<void(char)> DFS = [&](char current) {
    visited[current] = true;
    for (int next_vertex : adj_list[current]) {
      str += next_vertex;
      if (!visited[next_vertex]) {
        DFS(next_vertex);
      }
      if (current != next_vertex)
        str += current;
    }
  };
  for (char i = 'a'; i < 'a' + k; i++) {
    for (char j = i; j < 'a' + k; j++) {
      adj_list[i].pb(j);
    }
  }
  DFS('a');
  debug(str);
  int ind = 0;
  for (int i = str.length() - 1; i >= 0; i--) {
    if (str[i] != str[0]) {
      ind = i;
      break;
    }
  }
  debug(ind);
  str = str.substr(0, ind + 1);
  debug(str);
  if (n >= str.length()) {
    int x = n / str.length();
    debug(x)
    while (x--)
      cout << str;
    for (int i = 0; i < n % (int)str.length(); i++)
      cout << str[i];
  } else {
    for (int i = 0; i < n % (int)str.length(); i++)
      cout << str[i];
  }
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
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
    cout << endl;
  }
}
