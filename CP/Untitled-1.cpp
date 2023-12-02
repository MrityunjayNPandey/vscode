#include <bits/stdc++.h>
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
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  sort(v.begin(), v.end());

  int ansMax = 0, ansMin = 0;
  int temp = k;
  int in = n - 2;
  while (temp--) {
    ansMax += v[in];
    in -= 2;
  }
  //////////////
  temp = k - 1;
  in = 0;
  int j = n - 1;
  while (temp--) {
    ansMin += v[in];
    in++;
    j--;
  }
  j--;
  ansMin += v[j];
  cout << ansMin << ' ' << ansMax;
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
