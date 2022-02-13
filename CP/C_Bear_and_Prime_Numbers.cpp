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
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

//Sieve of Eratosthenes, time complexity of O(N*log(logN))
unordered_map<int, int> ifprime;
vector<int> primetemp(MAX_N, 1), prime;
void SIEVE()
{
    for(int p = 2; p <= MAX_N; p++)
    {
        if(primetemp[p] == 1)
        {
            for(int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
    prime.pb(1);
    for(int i = 2; i <= MAX_N; i++)
    {
        if(primetemp[i] == 1)
        {
            prime.pb(i);
            ifprime[i]++;
        }
    }
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.pb(x);
    }
    debug(v);
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        ans = 0;
        auto p = lower_bound(prime.begin(), prime.end(), x);
        auto q = upper_bound(prime.begin(), prime.end(), y);
        debug(ans, x, y, *p, *q);
        for(auto j = p; j < q; j++)
        {
            debug(*j);
            int temp1 = (*j);
            for(int k = 0; k < n; k++)
            {
                if(v[k] % temp1 == 0)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif
        SIEVE();
    int Test = 1;
// cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

