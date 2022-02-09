// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve() {
  int n = 0, k = 0, ans = 0, b1x = 0, b1y = 0, ansb1 = 0;
  cin >> n;
  vector<vector<int>> vv;
  for (int i = 0; i < n; i++) {
    vector<int> tempv;

    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      tempv.pb(x);
    }
    vv.pb(tempv);
  }
  map<int, int> diff, sum;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      diff[i - j] += vv[i][j];
      sum[i + j] += vv[i][j];
    }
  }
  debug(diff, sum) vector<pair<int, int>> vpd, vps;
  for (auto i : diff) {
    vpd.pb({i.second, i.first});
  }
  sort(all(vpd));
  for (auto i : sum) {
    vps.pb({i.second, i.first});
  }
  sort(all(vps));
  debug(vps, vpd) int x =
      (vps[vps.size() - 1].first > vpd[vpd.size() - 1].first) ? 1 : 0;
  debug(vps[vps.size() - 1].first, vpd[vpd.size() - 1].first);
  debug(x);
  int ansb1x = 0, ansb1y = 0;
  if (vps[vps.size() - 1].first > vpd[vpd.size() - 1].first) {
    int x1 = 0;
    for (int i = 0; i < n; i++) {
      if (diff[2 * i - vps[vps.size() - 1].second] > x1) {
        x1 = diff[2 * i - vps[vps.size() - 1].second];
        ansb1x = i;
        ansb1y = vps[vps.size() - 1].second - i;
      }
    }
    ans += x1 + vps[vps.size() - 1].first - vv[ansb1x][ansb1y];
    ansb1 = ans;
    // cout << ansb1x + 1 << " " << ansb1y + 1;
    b1x = ansb1x;
    b1y = ansb1y;
  } else if (vps[vps.size() - 1].first < vpd[vpd.size() - 1].first) {
    int x2 = 0;
    for (int i = 0; i < n; i++) {
      if (sum[vpd[vpd.size() - 1].second + 2 * i] > x2) {
        x2 = sum[vpd[vpd.size() - 1].second + 2 * i];
        ansb1x = vpd[vpd.size() - 1].second + i;
        ansb1y = i;
      }
    }
    ans += x2 + vpd[vpd.size() - 1].first - vv[ansb1x][ansb1y];
    ansb1 = ans;
    // cout << ansb1x + 1 << " " << ansb1y + 1;
    b1x = ansb1x;
    b1y = ansb1y;
  } else {
    int ansb11x = 0, ansb11y = 0, ansb12x = 0, ansb12y = 0, x1 = 0, ans1 = 0,
        ans2 = 0;
    for (int i = 0; i < n; i++) {
      if (diff[2 * i - vps[vps.size() - 1].second] > x1) {
        x1 = diff[2 * i - vps[vps.size() - 1].second];
        ansb11x = i;
        ansb11y = vps[vps.size() - 1].second - i;
      }
    }
    ans1 += x1 + vps[vps.size() - 1].first - vv[ansb11x][ansb11y];
    int x2 = 0;
    for (int i = 0; i < n; i++) {
      if (sum[vpd[vpd.size() - 1].second + 2 * i] > x2) {
        x2 = sum[vpd[vpd.size() - 1].second + 2 * i];
        ansb12x = vpd[vpd.size() - 1].second + i;
        ansb12y = i;
      }
    }
    ans2 += x2 + vpd[vpd.size() - 1].first - vv[ansb12x][ansb12y];
    debug(ans1, ans2) ansb1 = max(ans1, ans2);
    if (ans1 >= ans2) {
      // cout << ansb11x + 1 << " " << ansb11y + 1;
      b1x = ansb11x;
      b1y = ansb11y;
    } else {
      // cout << ansb12x + 1 << " " << ansb12y + 1;
      b1x = ansb12x;
      b1y = ansb12y;
    }
  }
  int ans2 = 0;
  b1x++;
  int b2x = 0, b2y = 0;
  for (int i = b1x; i < n; i += 2) {
    int tp = sum[b1x + b1y] + diff[b1x - b1y] - vv[b1x][b1y];
    if (tp > ans2) {
      ans2 = tp;
      b2x = i;
      b2y = b1y;
    }
  }
  b1x--;
  b1y--;
  for (int i = b1y; i >= 0; i -= 2) {
    int tp = sum[b1x + b1y] + diff[b1x - b1y] - vv[b1x][b1y];
    if (tp > ans2) {
      ans2 = tp;
      b2x = i;
      b2y = b1y;
    }
  }
  b1y++;
  b1x--;
  for (int i = b1x; i >= 0; i -= 2) {
    int tp = sum[b1x + b1y] + diff[b1x - b1y] - vv[b1x][b1y];
    if (tp > ans2) {
      ans2 = tp;
      b2x = i;
      b2y = b1y;
    }
  }
  b1x++;
  b1y++;
  for (int i = b1y; i < n; i += 2) {
    int tp = sum[b1x + b1y] + diff[b1x - b1y] - vv[b1x][b1y];
    if (tp > ans2) {
      ans2 = tp;
      b2x = i;
      b2y = b1y;
    }
  }
  b1y--;
  cout << ans2 + ansb1 << endl
       << b1x + 1 << " " << b1y + 1 << " " << b2x + 1 << " " << b2y + 1;
}
// clang-format off
int32_t main()
{
    ios;
    #ifdef SUBLIME
    free
    #endif
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef DEBUG
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}

