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

void solve()
{
    int n, i, j = 0, q = 0, r = 0;
    vector<pii> v;
    cin >> n;
    int a[n], t[n], p[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < n; i++)
    {
        v.pb({a[i], i});
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            r++;
    }
    if (r == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(all(v));
        q = n;
        for (i = 0; i < n; i++)
        {
            if (v[i].ss >= i && v[i].ff != v[i + 1].ff && v[i].ss != 0)
                j++;
        }
        cout << j << endl;
        for (i = 0; i < n; i++)
        {
            //cout << "iter" << i << " " << v[i].ss << endl;
            if (v[i].ss > i)
                cout << i + 1 << " " << v[i].ss + 1 << " " << v[i].ss - i << endl;
            else if (v[i].ss == i && v[i].ff != v[i + 1].ff && v[i].ss != 0)
                {
                    if(i+1==n)
                    cout << i  << " " << v[i].ss + 1 << " " << 1 << endl;
                    else
                    {
                        cout << i + 1 << " " << v[i].ss + 2 << " " << 1 << endl;
                    }
                }
        }
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
        //cout << endl;
    }
}