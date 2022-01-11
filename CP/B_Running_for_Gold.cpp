#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
const long long MAX_N = 1e7 + 5;
const long long MOD = 1e9 + 7;

const long long N = 5001;

int I;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5, 0));
    vector<pii> dp[5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }
    int w = 0;
    {
    function<bool(int, int)> f = [&](int win, int q)
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            if (a[win][i] < a[q][i])
                ans++;
        }
        return ans >= 3;
    };
    for (int i = 1; i < n; i++)
    {
        if (!f(w, i))
        {
            w = i;
        }
    }
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (i == w)
            continue;
        if (!f(w, i))
        {
            ans = false;
            break;
        }
    }
    cout << (ans ? w + 1 : -1) << nl;
}

int32_t main()
{
    ios;
    int Test = 1;
    cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        solve();
    }
}