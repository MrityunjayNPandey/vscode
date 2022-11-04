/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 30-08-2022 20:52:33
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
    int init_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
            init_value += i;
        else
            init_value += n - i - 1;
    }
    vector<int> vl, vr;
    for (int i = 0; i < n / 2; i++)
    {
        vl.pb(str[i]);
        vr.pb(str[n - i - 1]);
    }
    debug(vl, vr);
    vector<int>
        ansk;
    for (int i = 0; i < n / 2; i++)
    {
        if (vl[i] == 'L')
        {
            init_value -= i;
            init_value += n - i - 1;
            ansk.pb(init_value);
        }
        if (vr[i] == 'R')
        {
            init_value -= i;
            init_value += n - i - 1;
            ansk.pb(init_value);
        }
    }
    debug(ansk);
    for (int i = 0; i < ansk.size(); i++)
    {
        cout << ansk[i] << " ";
    }
    if (ansk.size() == 0)
    {
        for (int i = 0; i < n - ansk.size(); i++)
            cout << init_value << " ";
        return;
    }
    for (int i = 0; i < n - ansk.size(); i++)
        cout << ansk[ansk.size() - 1] << " ";
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