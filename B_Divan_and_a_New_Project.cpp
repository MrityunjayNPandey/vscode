// clang-format off
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL 
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
#define pb push_back
#define mkpa make_pair
#define mktu make_tuple
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define free freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n;
    vector<tiii> vt;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vt.pb(mktu(temp, i, 0));
    }
    debug(vt);
    sort(rall(vt));
    int rt = 0, lf = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            get<2>(vt[i]) = (++rt);
            time += (rt * 2 * get<0>(vt[i]));
        }
        else
        {
            get<2>(vt[i]) = 0 - (++lf);
            time += (lf * 2 * get<0>(vt[i]));
        }
    }
    cout << time << endl;
    cout << 0 << " ";
    for (int i = 0; i < n; i++)
    {
        cout << get<2>(vt[get<1>(vt[i])]) << " ";
    }
}

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
