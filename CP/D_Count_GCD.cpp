/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 06-11-2022 21:18:55
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
  int n = 0, m = 0, k = 0, ans = 1, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int gcd = v[0];
  map<int, vector<int>> mp;
  debug(v) debug(gcd, ans);

    //MKB iski

  auto generate = [&](vector<int> &factors, int limit) {
    int n = factors.size();
    long long ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      int set_bit = 0;
      int mul = 1;
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          mul = mul * factors[j];
          set_bit++;
        }
      }
      if (set_bit % 2 == 0)
        ans = ans + limit / mul;
      else
        ans = ans - limit / mul;
    }
    return ans;
  };

  for (int i = 1; i < n; i++) {
    if (__gcd(v[i], v[i - 1]) != v[i]) {
      cout << 0;
      return;
    } else {
      if (v[i] != v[i - 1]) {
        if (!mp.count(v[i - 1] / v[i])) {
          int n1 = v[i - 1] / v[i];
          for (int j = 2; j * j <= v[i - 1] / v[i]; j++) {
            if (n1 % j == 0) {
              mp[v[i - 1] / v[i]].pb(j);
              while (n1 % j == 0)
                n1 /= j;
            }
          }
          if (n1 > 1)
            mp[v[i - 1] / v[i]].pb(n1);
        }
        sort(all(mp[v[i - 1] / v[i]]));
        ans = (ans * generate(mp[v[i - 1] / v[i]], m / v[i])) % mod;
      } else {
        ans = (ans * (m / v[i])) % mod;
      }
    }
  }

  debug(gcd, ans);
  cout << ans;
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
    cout << endl;
  }
}
