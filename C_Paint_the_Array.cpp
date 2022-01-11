#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define nl "\n"
#define ok cout << "OK\n"
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define free                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define ff first
#define ss second
typedef pair<int, int> pii;
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;

int I;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> o, e;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cin >> a[i];
            o.pb(a[i]);
        }
        else
        {
            cin >> a[i];
            e.pb(a[i]);
        }
    }
    sort(all(o));
    sort(all(e));
    int gcd1 = gcd(o[0], o[1]);
    int gcd2 = gcd(e[0], e[1]);
    int q = 0, r = 0;
    // cout << gcd1 << " " << gcd2 << endl;
    if (n == 2)
    {
        cout << max(a[0], a[1]);
    }
    else if (gcd1 == gcd2 || o[0] < gcd1 || o[1] < gcd2 || (gcd1 == 1 && o[0] != 1) || (gcd2 == 1 && e[0] != 0))
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < o.size(); i++)
        {
            if (o[i] % gcd1 != 0)
            {
                cout << 0;
                q++;
                break;
            }
        }
        if (q == 0)
        {
            for (int i = 0; i < e.size(); i++)
            {
                if (e[i] % gcd2 != 0)
                {
                    cout << 0;
                    q++;
                    break;
                }
            }
        }
        if (q == 0)
        {
            cout << max(gcd1, gcd2);
        }
        else
            cout << 0;
    }
}
int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
        cout << endl;
    }
}
