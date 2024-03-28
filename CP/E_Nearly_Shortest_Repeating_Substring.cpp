/**
 *      codeforces: _joKer_0
 *      created: 28-03-2024 21:26:49
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

bool valid(string &str, int x) {
  int n = str.length();
  map<string, int> mp;
  string nTemp;
  for (int i = 0; i + x <= n; i += x) {
    nTemp = "";
    for (int j = i; j < i + x; j++) {
      nTemp += str[j];
    }
    mp[nTemp]++;
  }
  int mx = 0;
  string temp;
  for (auto &[l, r] : mp) {
    if (r > mx) {
      mx = r;
      temp = l;
    }
  }
  int cnt = 0;
  for (int i = 0; i + x <= n; i += x) {
    for (int j = i; j < i + x; j++) {
      if (str[j] != temp[j - i]) {
        cnt++;
      }
      if (cnt > 1) {
        break;
      }
    }
  }
  return cnt <= 1;
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str;
  cin >> str;
  set<int> factors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      factors.insert(i);
      factors.insert(n / i);
    }
  }
  vector<int> v;
  for (auto &i : factors) {
    v.pb(i);
  }
  ans = n;
  int l = 0, r = v.size() - 1;
  for (int i = 0; i < v.size(); i++) {
    if (valid(str, v[i])) {
      cout << v[i];
      return;
    }
  }
  cout << n;
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
