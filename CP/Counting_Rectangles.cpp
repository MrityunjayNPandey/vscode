/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-08-2022 21:37:57
 **/
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0, q;
    vector<pair<int, int>> width, height;
    vector<pair<int, pair<int, int>>> area;
    cin >> n >> q;
    int l, b;
    BIT<1050,1050> vv;
    // vector<vector<int>> vv(1001, vector<int>(1001, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> l >> b;
        vv[l][b]++;
    }
    for (int i = 0; i <= 1000; i++)
    {
        cnt = 0;
        for (int j = 0; j <= 1000; j++)
        {
            if (vv[i][j] != 0)
                cnt += (vv[i][j]) * (i * j);
            vv[i][j] = cnt;
        }
    }
    while (q--)
    {
        int l1, b1, l2, b2;
        ans = 0;
        cin >> l1 >> b1 >> l2 >> b2;
        debug(l1, l2, b1, b2);
        for (int i = l1 + 1; i < l2; i++)
        {
            ans += vv[i][b2 - 1] - vv[i][b1];
            debug(ans)
        }
        cout << ans << endl;
    }
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
        // cout << endl;
    }
}
