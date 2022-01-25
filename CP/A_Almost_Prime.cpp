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
#define int long long
int I;
// clang-format on

//Sieve of Eratosthenes, time complexity of O(N*log(logN))
unordered_map<int, int> mprime;
vector<int> primetemp(MAX_N, 1), prime;
void SIEVE()
{
    for (int p = 2; p <= MAX_N; p++)
    {
        if (primetemp[p] == 1)
        {
            for (int i = p * p; i <= MAX_N; i += p)
            {
                primetemp[i] = 0;
            }
        }
    }
    prime.pb(1);
    for (int i = 2; i <= MAX_N; i++)
    {
        if (primetemp[i] == 1)
        {
            prime.pb(i);
            mprime[i]++;
        }
    }
}

void solve()
{
    int n = 0, k = 0, ans = 0;
    cin >> n;
    for (int i = 4; i <= n; i++)
    {
        if (mprime[i] == 0)
        {
            debug(i)
            int k1 = 0;
            for (int j = 1; prime[j] < i; j++)
            {
                if (i % prime[j] == 0)
                {
                    debug(prime[j])
                    k1++;
                }
                if (k1 > 2)
                    break;
            }
            if (k1 == 2)
                k++;
        }
    }
    cout << k;
}

int32_t main()
{
    ios;
    int Test = 1;
    SIEVE();
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        cerr << "----" << I << "----" << nl;
        solve();
        cout << endl;
    }
}
