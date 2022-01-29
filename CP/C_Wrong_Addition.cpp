// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;
// clang-format on

void solve()
{
    int n = 0, k = 0, j = 0, ans = 0;
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> v;
    debug(str1,  str2)
    for (int i = min(str1.size(), str2.size()) - 1; i >= 0; i--)
    {
        if (str2[j] < str1[k])
        {
            if (str2[--j] != '1')
            {
                int temp = 10 + (int)(str2[j + 1] - '0') - (int)(str1[k] - '0');
                v.push_back(temp);
                debug(temp)
            }
            else
            {
                cout << -1;
                return;
            }
        }
        else
        {
            int temp = (int)(str2[j] - '0') - (int)(str1[k] - '0');
            v.push_back(temp);
            debug(temp);
        }
        j--;
        k--;
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
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
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
