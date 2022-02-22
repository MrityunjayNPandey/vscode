/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 20-02-2022 21:14:33
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

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.pb(x);
    }
    if(n <= 2)
    {
        cout << 0 << endl;
        for(int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1; i < n - 1; i++)
    {
        if(a[i] > a[i - 1] && a[i + 1] < a[i])
        {
            int r1 = a[i];
            int r2 = (i + 2 < n) ? a[i + 2] : INT_MIN;
            int ins = max(r1, r2);
            a[i + 1] = ins;
            ans++;
        }
    }
    cout << ans << endl;
    for(int i : a)
    {
        cout << i << " ";
    }
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

