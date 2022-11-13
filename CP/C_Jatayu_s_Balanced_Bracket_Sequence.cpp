/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 07-09-2022 00:33:33
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
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    string str;
    cin >> str;
    // vector<pair<int, int>> vvv(2 * n, {0, 0});
    // map<int, int> mpo;
    // map<int, vector<int>> mp;
    // for (int i = 0; i < 2 * n; i++)
    // {
    //     if (str[i] == '(')
    //     {
    //         k++;
    //         mpo[i] = k;
    //     }
    //     else
    //     {
    //         k--;
    //         mp[k].pb(i);
    //     }
    // }
    // debug(mp, mpo);
    // for (auto i : mpo)
    // {
    //     if (mp[i.second - 1].size())
    //     {
    //         cnt = 0;
    //         int ind = 0;
    //         if (i.second == 1)
    //         {
    //             ind = 2 * n + 1;
    //         }
    //         else
    //         {
    //             int x = upper_bound(mp[i.second - 2].begin(), mp[i.second - 2].end(), i.first) - mp[i.second - 2].begin();
    //             ind = mp[i.second - 2][x];
    //             debug(x, i.second)
    //                 debug(mp[i.second - 2]) if (mp[i.second - 2].size())
    //                     debug(mp[i.second - 2][x])
    //                         debug(i.first, i.second, ind);
    //         }
    //         auto x1 = upper_bound(mp[i.second - 1].begin(), mp[i.second - 1].end(), i.first);
    //         for (auto j = x1; j < mp[i.second - 1].end(); j++)
    //         {
    //             if (*j > i.first && *j < ind)
    //             {
    //                 if (vvv[*j].second == 1)
    //                 {
    //                     cnt++;
    //                 }
    //                 vvv[*j].second = 1;
    //             }
    //         }
    //         if (!cnt)
    //             ans++;
    //         debug(vvv, ans)
    //     }
    // }
    // cout << ans;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (str[i] == '(' && str[i + 1] == ')')
            cnt++;
    }
    cout << n - cnt + 1;
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
