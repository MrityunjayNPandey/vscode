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
    int n, a, time = 0;
    cin >> n;
    vector<pii> vp, vp1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vp.pb(make_pair(a, i));
    }
    sort(all(vp));
    int p;
    if ((n + 1) % 2 == 0)
    {
        p = (((n + 1) / 2) - 1);
    }
    else
    {
        p = (n + 1) / 2;
    }
    vp1.pb(make_pair(0, p));
    int k = 0, l = 1;
    for (int i = n; i >= 1; i--)
    {
        if (k % 2 == 0)
        {
            vp1.pb(make_pair(vp[i].ss, p + l));
            k++;
        }
        else
        {
            vp1.pb(make_pair(vp[i].ss, p - l));
            k++;
            l++;
        }
        time += 2 * l * vp[i].ff;
    }
    cout << time << endl;
    cout << p << " ";
    for (int i = 0; i < n; i++)
    {
        cout << i;
    }
}

int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        // solve();
        cout << "hkhn" << endl;
    }
}
