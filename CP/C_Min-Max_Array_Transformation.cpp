#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define print(x)
#define dclear(x)
#endif
#define free                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, lx, ly;
    cin >> n;
    debug(n);
    vector<int>
        a(n), b(n);
    multiset<int> mltst;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i], mltst.insert(b[i]);
    // for dmin:
    vector<int> dmin(n);
    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        dmin[i] = b[index] - a[i];
    }
    // for dmax:
    vector<int> dmax(n);
    for (int i = n - 1; i >= 0; i--)
    {
        dmax[i] = *mltst.rbegin() - a[i];
        mltst.erase(mltst.lower_bound(a[i]));
    }
    for (int i = 0; i < n; i++)
        cout << dmin[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << dmax[i] << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for (int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}
