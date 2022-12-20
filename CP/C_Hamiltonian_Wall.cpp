/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 12-12-2022 20:35:28
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  vector<vector<char>> str;
  vector<char> vt;
  for (int j = 0; j < n; j++) {
    vt.pb(str1[j]);
  }
  str.pb(vt);
  vt.clear();
  for (int j = 0; j < n; j++) {
    vt.pb(str2[j]);
  }
  str.pb(vt);
  debug(str);
  int x = -1, y = -1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      int p = 0, q = 0, r = 0, s = 0;
      if (str[i][j] == 'B') {
        if (j > 0) {
          if (str[i][j - 1] == 'B')
            p++;
        }
        if (j < n - 1) {
          if (str[i][j + 1] == 'B')
            q++;
        }
        if (i == 1) {
          if (str[i - 1][j] == 'B')
            r++;
        }
        if (i == 0) {
          if (str[i + 1][j] == 'B')
            s++;
        }
        if (p + q + r + s <= 1) {
          cnt++;
          x = i, y = j;
        }
      }
    }
  }
  debug(x, y);
  if (cnt >= 3) {
    cout << "NO\n";
    return;
  }
  if (x == -1 && y == -1) {
    for (int i = 0; i < n; i++) {
      if (str[0][i] == 'B')
        x = 0, y = i;
    }
    int x1=x, y1=y;
    vector<vector<char>> str1(str);
    while (1) {
      str[x][y] = '.';
      if (x == 0) {
        if (str[x + 1][y] == 'B') {
          str[x + 1][y] = '.';
          x++;
        } else if (y > 0 && str[x][y - 1] == 'B') {
          str[x][y - 1] = '.';
          y--;
        } else if (y < n - 1 && str[x][y + 1] == 'B') {
          str[x][y + 1] = '.';
          y++;
        } else {
          break;
        }
      } else {
        if (str[x - 1][y] == 'B') {
          str[x - 1][y] = '.';
          x--;
        } else if (y > 0 && str[x][y - 1] == 'B') {
          str[x][y - 1] = '.';
          y--;
        } else if (y < n - 1 && str[x][y + 1] == 'B') {
          str[x][y + 1] = '.';
          y++;
        } else {
          break;
        }
      }
    }
    debug(str);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (str[i][j] == 'B') {
          cnt++;
        }
      }
    }
    
    if (!cnt) {
      cout << "YES\n";
      return;
    }
    x=x1+1, y=y1;
    while (1) {
      str1[x][y] = '.';
      if (x == 0) {
        if (str1[x + 1][y] == 'B') {
          str1[x + 1][y] = '.';
          x++;
        } else if (y > 0 && str1[x][y - 1] == 'B') {
          str1[x][y - 1] = '.';
          y--;
        } else if (y < n - 1 && str1[x][y + 1] == 'B') {
          str1[x][y + 1] = '.';
          y++;
        } else {
          break;
        }
      } else {
        if (str1[x - 1][y] == 'B') {
          str1[x - 1][y] = '.';
          x--;
        } else if (y > 0 && str1[x][y - 1] == 'B') {
          str1[x][y - 1] = '.';
          y--;
        } else if (y < n - 1 && str1[x][y + 1] == 'B') {
          str1[x][y + 1] = '.';
          y++;
        } else {
          break;
        }
      }
    }
    debug(str1);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (str1[i][j] == 'B') {
          cout << "NO\n";
          return;
        }
      }
    }
    cout << "YES\n";
    return;
  }
  while (1) {
    str[x][y] = '.';
    if (x == 0) {
      if (str[x + 1][y] == 'B') {
        str[x + 1][y] = '.';
        x++;
      } else if (y > 0 && str[x][y - 1] == 'B') {
        str[x][y - 1] = '.';
        y--;
      } else if (y < n - 1 && str[x][y + 1] == 'B') {
        str[x][y + 1] = '.';
        y++;
      } else {
        break;
      }
    } else {
      if (str[x - 1][y] == 'B') {
        str[x - 1][y] = '.';
        x--;
      } else if (y > 0 && str[x][y - 1] == 'B') {
        str[x][y - 1] = '.';
        y--;
      } else if (y < n - 1 && str[x][y + 1] == 'B') {
        str[x][y + 1] = '.';
        y++;
      } else {
        break;
      }
    }
  }
  debug(str);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      if (str[i][j] == 'B') {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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

/*
Did I ever tell you what the definition of insanity is?
Insanity is doing the exact... same fucking thing... over and over again
expecting... shit to change... That. Is. Crazy. The first time somebody told me
that, I dunno, I thought they were bullshitting me. The thing is... He was
right. And then I started seeing, everywhere I looked, everywhere I looked all
these fucking pricks, everywhere I looked, doing the exact same fucking thing...
over and over and over and over again thinking 'this time is gonna be different'
no, no, no please... This time is gonna be different, I'm sorry, I don't like...
The way...

Okay, Do you have a fucking problem in your head, do you think I am bullshitting
you, do you think I am lying? Fuck you! Okay? Fuck you!...
*/
