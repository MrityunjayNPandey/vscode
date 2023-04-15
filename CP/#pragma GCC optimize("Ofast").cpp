
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
#define int long long
#define float long double
#define endl "\n"
#define watch(x) clog << "[" << _LINE_ << "] " << (#x) << " = " << (x) << endl

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int a, b;
    int l, r, ans = 0;
    cin >> l >> r;
    int l1 = l, r1 = r;
    for (int i = l1; i <= r1; i++) {
      int cnt = 0;
      l = l1, r = r1;
      while (l < r) {
        int mid = (l + r) / 2;
        if (i < mid) {
          r = mid - 1;
        } else if (i > mid) {
          l = mid + 1;
        } else {
          cnt++;
          break;
        }
      }
      if (!cnt) {
        ans++;
      }
    }
    cout << ans;
  }
  return 0;
}