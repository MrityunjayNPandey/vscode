// clang-format off
#include <bits/stdc++.h>
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
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const long long INF = 1ll << 32;
const long long MAX_N = 1e6 + 7;
const long long MOD = 998244353;
const long long mod = 998244353;
// #define int long long
int I;
// clang-format on

void solve()
{
    string str;
    int p = 0, maxa = 0, t = 0, max2 = 0, potans = 0, max1 = 0, start = 0, met = 0;
    cin >> str;
    // debug((int)(str[0]-'0'));

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != 0)
            p++;
        if (p != 0)
        {
            if (met == 0)
            {
                start = i;
                met++;
            }
            maxa += str[i] - '0';
            // debug(maxa);
            if (t == 1)
            {
                max1 = maxa;
                if (max1 / 10 > 0)
                {
                    potans = i;
                    debug(max1);
                    break;
                }
            }
            if (t >= 2)
            {
                maxa -= (int)str[i - 2] - '0';
                debug(maxa);
                if (maxa / 10 > 0)
                {
                    int maxtemp = max2;
                    max2 = max(max2, maxa);
                    debug(max2);
                    if (maxtemp != max2)
                    {
                        potans = i;
                        //
                    }
                }
            }
            t++;
        }
    }
    max1 = (max1, max2);
    if (max1 == 0)
        max1 = maxa;
    if (potans == 0)
    {
        potans = 1;
    }
    debug(maxa);
    {
        str[potans - 1] = (char)(max1 / 10) + '0';
        str[potans] = (char)(max1 % 10) + '0';
    }
    debug(str[potans - 1]);
    debug(str[potans]);
    debug(str);
    int p1 = 0;
    for (int i = start; i < str.length(); i++)
    {
        if (str[start] == '0' && p1 == 0)
        {
            p1++;
            continue;
        }
        cout << str[i];
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
