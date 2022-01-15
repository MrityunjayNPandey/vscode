#include "bits/stdc++.h"
using namespace std;
#define pb push_back
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
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x)         \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
#define int long long
int I;

void solve()
{
    int n = 0, potans = 0, ans = 0;
    cin >> n;
    vector<vector<int>> vv;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < 5; j++)
        {
            int temp;
            cin >> temp;
            v.pb(temp);
        }
        vv.pb(v);
    }
    // debug(vv);
    vector<int> vt1;
    int p = 0, temp = -1;
    vector<int> vt;
    while (temp != 1 && temp != 0)
    {
        debug(vt);
        if (p == 0)
        {
            for (int i = 1; i < n; i++)
            {
                int t = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (vv[i][j] < vv[0][j])
                    {
                        t++;
                    }
                    if (t == 3)
                    {
                        vt.pb(i);
                        temp++;
                        break;
                    }
                }
            }
            p++;
            // debug(vt);
            if (temp == -1)
            {
                ans = 1;
                break;
            }
            if (temp == 0)
            {
                potans = vt[0] + 1;
                break;
            }
        }
        temp = 0;
        debug(vt);
        p = vt[0];
        vector<int> vt1;
        for (int i = 1; i < vt.size(); i++)
        {
            int t = 0;
            for (int j = 0; j < 5; j++)
            {
                if (vv[vt[i]][j] < vv[vt[0]][j])
                {
                    t++;
                }
                if (t == 3)
                {
                    vt1.pb(vt[i]);
                    temp++;
                    break;
                }
            }
        }
        vt.clear();
        vector<int> vt(vt1);
        debug(vt1);
        vt1.clear();
        if (temp == 0)
        {
            potans = p + 1;
            debug(temp);
            break;
        }
        if (temp == 1)
        {
            potans = vt[0] + 1;
            debug(temp);
            break;
        }
    }
    debug(potans);
    debug(ans);
    if (temp != -1)
    {
        ans = potans;
        // debug(vv)
        for (int i = 0; i < n; i++)
        {
            int t = 0;
            for (int j = 0; j < 5; j++)
            {
                if (vv[i][j] < vv[potans - 1][j])
                {
                    t++;
                }
                if (t == 3)
                {
                    ans = -1;
                    break;
                }
            }
            if (ans == -1)
            {
                debug(i);
                break;
            }
        }
    }
    debug(ans);
    cout << ans;
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
