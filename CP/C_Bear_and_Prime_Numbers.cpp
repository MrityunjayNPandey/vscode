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
const long long INF = 1ll << 32; const long long MAX_N = 1e7 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
int I;

int a[10000005], qzh[1000005];

int primes[10000005];
int prime_num = 1;
bool is_not_primes[10000005] = { false };

map<int, int> mp;

int read()
{
    int x = 0; int zf = 1; char ch = ' ';
    while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if(ch == '-') zf = -1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}

void getPrime(int n)
{
    is_not_primes[0] = true;
    is_not_primes[1] = true;
    for(int i = 2; i <= n; i++)
    {
        if(is_not_primes[i] == false)
            primes[prime_num++] = i;
        for(int j = 1; (j < prime_num) && (primes[j] * i <= n); j++)
        {
            is_not_primes[primes[j] * i] = true;
            if((i % primes[j]) == 0)
                break;
        }
    }
}


void solve()
{
    getPrime(10000000);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        ++a[x];
    }
    for(int i = 1; i < prime_num; ++i)
        for(int j = primes[i]; j <= 10000000; j += primes[i])
            qzh[i] += a[j];
    for(int i = 1; i < prime_num; ++i)
        qzh[i] += qzh[i - 1];
    int m = 0, l, r;
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        l = 0, r = 0;
        cin >> l >> r;
        int ans_r = qzh[lower_bound(primes + 1, primes + prime_num, r + 1) - primes - 1];
        int ans_l = qzh[lower_bound(primes + 1, primes + prime_num, l) - primes - 1];
        cout << ans_r - ans_l << endl;
    }
}



//Sieve of Eratosthenes, time complexity of O(N*log(logN))
unordered_map<int, int> ifprime;
vector<int> primetemp(MAX_N, 1), prime;
void SIEVE()
{
    prime.pb(1);
    for(int p = 2; p <= MAX_N; p++)
    {
        if(primetemp[p] == 1)
        {
            prime.pb(i);
            for(int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
}



int32_t main()
{
    ios;
#ifdef SUBLIME
    free
#endif

        int Test = 1;
    // cin >> Test;
    for(I = 1; I <= Test; I++)
    {
        cerr << "-------" << I << "-------" << endl;dclear();
        solve();
        cout << endl;
    }
}

