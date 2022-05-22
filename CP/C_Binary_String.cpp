/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 13-05-2022 20:57:17
**/
#include <bits/stdc++.h>
using namespace std;
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
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    string str;
    cin >> str;
    vector<int> pref1, suff1, pref0, suff0;
    int one = 0, zero = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '1')
        {
            one++;
        } else
            zero++;
        pref1.pb(one);
        pref0.pb(zero);
    }
    int rm0 = zero;
    int rf1 = 0;
    one = 0, zero = 0;
    for(int i = str.length() - 1; i >= 0; i--)
    {
        if(str[i] == '1')
        {
            one++;
        } else
            zero++;
        suff1.pb(one);
        suff0.pb(zero);
    }
    for(int i = 0; i < str.length(); i++)
    {
        pref1[i] += suff1[i];
        pref0[i] += suff0[i];
    }
    for(int i = 0; i < str.length(); i++)
    {
        rf1 += pref1[i];
        rm0 -= pref0[i];
        if(rf1 > rm0)
        {
            ans = min(rf1, rm0+pref0[i]);
            break;
        }
    }
    cout<<ans;
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

