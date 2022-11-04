/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 26-07-2022 18:35:46
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
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m >> k;
    vector<int> v(k);
    for(int i = 0; i < k; i++)
        cin >> v[i];
    sort(rall(v));
    debug(v)
    //row wise
        int x = m;
    map<int, int> mp;
    for(int i = 0; i < k; i++)
    {
        if(v[i] >= n * 2)
        {
            mp[i] += v[i] - n * 2;
            x -= 2;
            if(x == 0)
            {
                cout << "Yes";
                return;
            }
            if(x < 0)
            {
                x += 2;
                mp.erase(i);
                break;
            }
        }
    }
    debug(x, mp);
    for(auto i : mp)
    {
        int p = i.second / n;
        x -= p;
        if(x <= 0)
        {
            cout << "Yes";
            return;
        }
    }
//column wise
    x = n, cnt = 0;
    map<int, int> mp1;
    for(int i = 0; i < k; i++)
    {
        if(v[i] >= m * 2)
        {
            mp1[i] += v[i] - m * 2;
            x -= 2;
            if(x == 0)
            {
                cout << "Yes";
                return;
            }
            if(x < 0)
            {
                x += 2;
                mp1.erase(i);
                break;
            }
        }
    }
    debug(x, mp1)
        for(auto i : mp1)
        {
            int p = i.second / m;
            x -= p;
            if(x <= 0)
            {
                cout << "Yes";
                return;
            }
        }
    cout << "No";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}
