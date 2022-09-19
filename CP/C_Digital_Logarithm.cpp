/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-09-2022 21:26:53
 **/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#define print(x)
#define dclear(x)
#endif
#define free                            \
    freopen("input.txt", "r", stdin);   \
    freopen("output.txt", "w", stdout); \
    freopen("error.txt", "w", stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const long long INF = LONG_LONG_MAX;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
#define int long long

int len(int x)
{
    string str = to_string(x);
    return str.length();
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> mp1, mp2, mpn1, mpn2;
    multiset<int> s, t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (s.find(b[i]) == s.end())
            t.insert(b[i]);
        else
            s.erase(s.find(b[i]));
    }
    while (!s.empty() || !t.empty())
    {
        if (*s.rbegin() > *t.rbegin())
        {
            if (t.find(len(*s.rbegin())) == t.end())
                s.insert(len(*s.rbegin()));
            else
                t.erase(t.find(len(*s.rbegin())));
            s.erase(--s.end());
            ans++;
        }
        else if (*s.rbegin() < *t.rbegin())
        {
            if (s.find(len(*t.rbegin())) == s.end())
                t.insert(len(*t.rbegin()));
            else
                s.erase(s.find(len(*t.rbegin())));
            t.erase(--t.end());
            ans++;
        }
        else
        {
            s.erase(--s.end()), t.erase(--t.end());
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for (int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}
