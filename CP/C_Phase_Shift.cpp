/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 04-10-2022 15:34:26
 **/
// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int I, Test, bitest;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  string str;
  cin >> n;
  cin >> str;
  n = str.length();
  map<char, pair<char, char>> mp;
  char st = 'a';
  for (int i = 0; i < str.length(); i++) {
    if (mp.count(str[i])) {
      if (mp[str[i]].first != '0') {
        cout << mp[str[i]].first;
        continue;
      }
    }
    for (char j = st; j <= 'z'; j++) {
      if (j == str[i])
        continue;
      if (!mp.count(j)) {
        mp[j] = {'0', str[i]};
        if (mp.count(str[i]))
          mp[str[i]] = {j, mp[str[i]].second};
        else
          mp[str[i]] = {j, '0'};
        break;
      } else {
        if (mp[j].second == '0') {
          if (mp.count(str[i])) {
            if (mp[str[i]].second != '0' && j != 'z') {
              char z = j;
              int k = 1;
              while (mp[z].first != '0' && mp[z].first != str[i] && k < 26) {
                debug(str[i], z, mp[z], k);
                z = mp[z].first;
                k++;
              }
              dclear(I);
              if (mp[z].first == str[i] && k!=25) {
                debug(mp[z])
                continue;
              }
            }
          }
          mp[j] = {mp[j].first, str[i]};
          if (mp.count(str[i]))
            mp[str[i]] = {j, mp[str[i]].second};
          else
            mp[str[i]] = {j, '0'};
          break;
        }
      }
    }
    cout << mp[str[i]].first;
  }
  debug(mp) cout << endl;
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
