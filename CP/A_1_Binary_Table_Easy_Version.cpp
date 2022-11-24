/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 22-11-2022 13:54:16
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
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LLONG_MAX-INT_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = INF, cnt = 0, sum = 0;
  cin >> n >> m;
  vector<string> vstr(n);
  for (auto &i : vstr) {
    cin >> i;
  }
  vector<pair<int, int>> vans;
  for (int i = 0; i < n - 1; i += 2) {
    for (int j = 0; j < m - 1; j += 2) {
      int on = (vstr[i][j] == '1') ? 1 : 0;
      int tw = (vstr[i][j + 1] == '1') ? 1 : 0;
      int th = (vstr[i + 1][j] == '1') ? 1 : 0;
      int fr = (vstr[i + 1][j + 1] == '1') ? 1 : 0;
      if (on + tw + th + fr == 1) {
        if (on == 1) {
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
        }
        if (tw == 1) {
          vans.pb({i, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
        }
        if (th == 1) {
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
        if (fr == 1) {
          vans.pb({i + 1, j + 1});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
      }
      if (on + tw + th + fr == 2) {
        if (on + tw == 2) {
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
        if (on + th == 2) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
        if (tw + fr == 2) {
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
        }
        if (th + fr == 2) {
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
        }
        if (on + fr == 2) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
        if (tw + th == 2) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }
      }
      if (on + tw + th + fr == 3) {
        if (on + tw + th == 3) {
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i, j + 1});
        }
        if (on + tw + fr == 3) {
          vans.pb({i, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
        }
        if (on + th + fr == 3) {
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
        }
        if (tw + th + fr == 3) {
          vans.pb({i, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
        }
      }
      if (on + tw + th + fr == 4) {
        vans.pb({i, j});
        vans.pb({i, j + 1});
        vans.pb({i + 1, j + 1});
        vans.pb({i + 1, j});
        vans.pb({i, j});
        vans.pb({i, j + 1});
        vans.pb({i, j});
        vans.pb({i + 1, j});
        vans.pb({i + 1, j + 1});
        vans.pb({i, j + 1});
        vans.pb({i + 1, j + 1});
        vans.pb({i + 1, j});
      }

      vstr[i][j] = '0';
      vstr[i][j + 1] = '0';
      vstr[i + 1][j + 1] = '0';
      vstr[i + 1][j] = '0';
    }
  }
  if (n % 2) {
    for (int i = n - 2; i < n - 1; i += 2) {
      for (int j = 0; j < m - 1; j += 2) {
        int on = (vstr[i][j] == '1') ? 1 : 0;
        int tw = (vstr[i][j + 1] == '1') ? 1 : 0;
        int th = (vstr[i + 1][j] == '1') ? 1 : 0;
        int fr = (vstr[i + 1][j + 1] == '1') ? 1 : 0;
        if (on + tw + th + fr == 1) {
          if (on == 1) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (tw == 1) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (th == 1) {
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (fr == 1) {
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 2) {
          if (on + tw == 2) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (on + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (th + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (on + fr == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 3) {
          if (on + tw + th == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
          }
          if (on + tw + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
          }
          if (on + th + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (tw + th + fr == 3) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
        }
        if (on + tw + th + fr == 4) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }

        vstr[i][j] = '0';
        vstr[i][j + 1] = '0';
        vstr[i + 1][j + 1] = '0';
        vstr[i + 1][j] = '0';
      }
    }
  }
  if (m % 2) {
    for (int i = 0; i < n - 1; i += 2) {
      for (int j = m - 2; j < m - 1; j += 2) {
        int on = (vstr[i][j] == '1') ? 1 : 0;
        int tw = (vstr[i][j + 1] == '1') ? 1 : 0;
        int th = (vstr[i + 1][j] == '1') ? 1 : 0;
        int fr = (vstr[i + 1][j + 1] == '1') ? 1 : 0;
        if (on + tw + th + fr == 1) {
          if (on == 1) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (tw == 1) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (th == 1) {
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (fr == 1) {
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 2) {
          if (on + tw == 2) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (on + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (th + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (on + fr == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 3) {
          if (on + tw + th == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
          }
          if (on + tw + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
          }
          if (on + th + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (tw + th + fr == 3) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
        }
        if (on + tw + th + fr == 4) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }

        vstr[i][j] = '0';
        vstr[i][j + 1] = '0';
        vstr[i + 1][j + 1] = '0';
        vstr[i + 1][j] = '0';
      }
    }
  }
  if (m % 2 && n & 1) {
    for (int i = n-2; i < n - 1; i += 2) {
      for (int j = m - 2; j < m - 1; j += 2) {
        int on = (vstr[i][j] == '1') ? 1 : 0;
        int tw = (vstr[i][j + 1] == '1') ? 1 : 0;
        int th = (vstr[i + 1][j] == '1') ? 1 : 0;
        int fr = (vstr[i + 1][j + 1] == '1') ? 1 : 0;
        if (on + tw + th + fr == 1) {
          if (on == 1) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (tw == 1) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (th == 1) {
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (fr == 1) {
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 2) {
          if (on + tw == 2) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (on + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (th + fr == 2) {
            vans.pb({i, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
          }
          if (on + fr == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
          if (tw + th == 2) {
            vans.pb({i, j});
            vans.pb({i, j + 1});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i + 1, j});
          }
        }
        if (on + tw + th + fr == 3) {
          if (on + tw + th == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i, j + 1});
          }
          if (on + tw + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j + 1});
            vans.pb({i, j + 1});
          }
          if (on + th + fr == 3) {
            vans.pb({i, j});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
          if (tw + th + fr == 3) {
            vans.pb({i, j + 1});
            vans.pb({i + 1, j});
            vans.pb({i + 1, j + 1});
          }
        }
        if (on + tw + th + fr == 4) {
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
          vans.pb({i, j});
          vans.pb({i, j + 1});
          vans.pb({i, j});
          vans.pb({i + 1, j});
          vans.pb({i + 1, j + 1});
          vans.pb({i, j + 1});
          vans.pb({i + 1, j + 1});
          vans.pb({i + 1, j});
        }

        vstr[i][j] = '0';
        vstr[i][j + 1] = '0';
        vstr[i + 1][j + 1] = '0';
        vstr[i + 1][j] = '0';
      }
    }
  }
  debug(vstr)
  cout << vans.size() / 3 << endl;
  for (auto [l, r] : vans) {
    cout << l + 1 << " " << r + 1 << " ";
    if (k == 2)
      cout << endl;
    k++;
    if (k == 3)
      k = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
