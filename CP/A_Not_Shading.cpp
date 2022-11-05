#include <bits/stdc++.h>
using namespace std;
#define pb push_back
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " = ";                                                         \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
#define int long long
int I;

void solve() {
  int n = 0, m = 0, r = 0, c = 0, ans = 0;
  cin >> n >> m >> r >> c;
  string v[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (v[i][j] == 'B') {
        t++;
        break;
      }
  }
  if (((m == n && m == 1) && t == 0) || t == 0)
    cout << -1;
  else if (v[r - 1][c - 1] == 'B')
    cout << 0;
  else {
    for (int i = 0; i < n; i++) {
      if (v[i][c - 1] == 'B') {
        cout << 1;
        return;
      }
    }
    for (int i = 0; i < m; i++) {
      if (v[r - 1][i] == 'B') {
        cout << 1;
        return;
      }
    }
    cout << 2;
  }
}

int32_t main() {
  ios;
  int Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    solve();
    cout << endl;
  }
}
