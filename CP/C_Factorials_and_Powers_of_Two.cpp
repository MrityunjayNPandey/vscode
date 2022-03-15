/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 04-03-2022 22:03:09
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
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

vector<int> factorial, pow2, seq;
map<int, int> mp;

void pref()
{
    factorial.pb(1);
    pow2.pb(1);
    mp[1]++;
    for(int i = 1; i < 15; i++)
    {
        factorial.pb(factorial[i - 1] * i);
        mp[factorial[i]]++;
    }
    for(int i = 1; i < 41; i++)
    {
        pow2.pb(pow(2, i));
        mp[pow2[i]]++;
    }
    for(auto i : mp)
    {
        seq.pb(i.first);
    }
    debug(factorial, pow2, seq)
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    for(int i = seq.size(); i >= 0; i--)
    {
        debug(i);
        if(n >= seq[i])
        {
            n -= seq[i];
            sum+=seq[i];
            debug(i, seq[i], sum);
            if(seq[i] != 0)
                ans++;
        }
    }
    if(n != 0)
    {
        cout << -1;
        return;
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        pref();
    int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

