/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 16-02-2022 19:16:44
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define dclear()
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;

typedef long long ll;
int I;

void solve()
{
    int n, d;
    cin >> n >> d;
    int a[n];
    int leftpt = 0, rightpt = 0;
    long long int sum = 0, k;
    for(int i = 0;i < n;i++)cin >> a[i];
    for(rightpt = 2;rightpt < n;rightpt++)
    {
        while(a[rightpt] - a[leftpt] > d)leftpt++;
        k = rightpt - leftpt;
        sum += k * (k - 1) / 2;
    }
    cout << sum;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
#ifdef DEBUG
        clog << "-------" << I << "-------" << endl;dclear();
#endif
        solve();
        cout << endl;
    }
}

