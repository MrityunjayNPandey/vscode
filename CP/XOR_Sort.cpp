#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define free                                                                   \
  freopen("input.txt", "r", stdin);                                            \
  freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef long double ld;
const long long INF = 1ll << 32;
const int MAX_N = 2e5 + 5;
const long long MOD = 1e9 + 7;
const long long N = 9999999;
long double pi = 3.1415926535;

void show(vector<int> a) {
  for (auto it : a)
    cout << it << " ";
  cout << nl;
}
int I;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> z[n + 1];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    z[x].pb(y);
    z[y].pb(x);
  }
  int sq = ceil(sqrt(n));
  vector<int> a, b, vis(n + 1), lvl(n + 1);
  function<void(int)> bfs = [&](int t) {
    vis[t] = 1;
    queue<int> q;
    q.push(t);
    lvl[t] = 0;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      if (lvl[f] == sq)
        continue;
      for (auto it : z[f]) {
        if (vis[it] == 0) {
          q.push(it);
          vis[it] = 1;
          b.pb(it);
          lvl[it] = lvl[f] + 1;
        }
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && a.size() < sq) {
      a.pb(i);
      bfs(i);
    }
  }
  if (a.size() + b.size() < n) {
    cout << -1 << endl;
    return;
  }
  cout << a.size() << endl;
  for (auto it : a)
    cout << it << " ";
  cout << endl;
}

int32_t main() {
  ios;
  int Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    solve();
  }
}