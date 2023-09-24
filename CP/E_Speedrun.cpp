/**
 *      codeforces: _joker_0
 *      created: 30-08-2023 22:08:34
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
  cin >> n >> m >> k;
  vector<int> h(n), vinit;
  for (auto &i : h)
    cin >> i;
  map<int, vector<int>> adj_list, unlocked, unlockedInit;
  map<int, int> locked, lockedInit;
  vector<pair<int, int>> vp;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    assert(x < y);
    vp.pb({x, y});
    adj_list[x].pb(y);
    locked[y]++;
  }
  debug(adj_list, locked) vector<int> completion(n, -INF);
  vector<int> starting;
  for (int i = 0; i < n; i++) {
    if (!locked.contains(i)) {
      unlocked[h[i]].pb(i);
      starting.pb(i);
    }
  }
  debug(starting) vector<int> v1;
  for (auto &[l, r] : unlocked) {
    v1.pb(l);
  }

  ans = LLONG_MAX;

  int currentTime = (*unlocked.begin()).first;
  int initTime = currentTime;
  int max_completion = 0;
  while (unlocked.size()) {
    auto [l, r] = *unlocked.begin();
    currentTime = l;
    int currentHour = currentTime % k;
    vector<int> temp;
    for (auto &p : r) {
      completion[p] = currentTime;
      max_completion = max(max_completion, currentTime);
      for (auto &i : adj_list[p]) {
        assert(locked[i] > 0);
        locked[i]--;
        if (locked[i] == 0) {
          locked.erase(i);
          if (h[i] % k < currentHour) {
            unlocked[currentTime - currentHour + k + h[i] % k].pb(i);
            if (currentTime - currentHour + k + h[i] % k == l) {
              temp.pb(i);
            }
          } else {
            unlocked[currentTime - currentHour + h[i] % k].pb(i);
            if (currentTime - currentHour + h[i] % k == l) {
              temp.pb(i);
            }
          }
        }
      }
    }
    debug(unlocked);
    unlocked.erase(unlocked.begin());
    if (temp.size()) {
      unlocked[l] = temp;
    }
  }
  debug(completion, max_completion)
      priority_queue<pair<int, int>, vector<pair<int, int>>,
                     greater<pair<int, int>>>
          pq;
  std::ranges::sort(starting, [&h](int v, int w) { return h[v] < h[w]; });
  for (int v : starting) {
    // Answer if we start at h[v]
    ans = min(ans, max_completion - completion[v]);
    // Bump vertex v to the next day, and calculate the consequences:
    completion[v] = h[v] + k;
    pq.push({completion[v], v});
    while (!pq.empty()) {
      auto [t, v] = pq.top();
      pq.pop();
      assert(t <= completion[v]);
      if (completion[v] < t)
        continue; // obsolete entry; v will be processed later
      max_completion = max(max_completion, completion[v]);
      for (int w : adj_list[v]) {
        int wait_time = h[w] - h[v];
        if (wait_time < 0)
          wait_time += k;
        if (completion[w] < completion[v] + wait_time) {
          completion[w] = completion[v] + wait_time;
          pq.push({completion[w], w});
        }
      }
    }
  }
  cout << ans << endl;
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