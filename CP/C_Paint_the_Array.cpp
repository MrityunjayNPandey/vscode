// clang-format off
#include "bits/stdc++.h"
using namespace std;
#define nl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, a = 0, b = 0, k = 0, ans = 0;
    cin >> n >> a >> b;
    debug(a,b);
    int gcd1 = a, gcd2 = b;
    map<int, int> mp1, mp2;
    for (int i = 2; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
        {
            gcd1 = __gcd(gcd1, temp);
            mp1[temp]++;
            if (mp2[temp])
            {
                cout << 0;
                return;
            }
        }
        else
        {
            gcd2 = __gcd(gcd2, temp);
            mp2[temp]++;
            if (mp1[temp])
            {
                cout << 0;
                return;
            }
        }
    }
    debug(gcd1, gcd2, a, b);
    if (__gcd(gcd1, gcd2) != 1 && gcd1 == gcd2)
    {
        cout << 0;
    }
    else
    {
        if (n == 2)
            cout << __gcd(a, b);
        else
            cout << max(gcd1, gcd2);
    }
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef LOCAL
        cerr << "-------" << I << "-------" << nl;
        #endif
        solve();
        cout << endl;
    }
}
