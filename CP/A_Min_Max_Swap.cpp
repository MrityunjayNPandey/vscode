// clang-format off
#include <chrono>
using namespace std::chrono;
high_resolution_clock::time_point t1 = high_resolution_clock::now();
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifndef LOCAL
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
    int n = 0, k = 0, ans = 0;
    cin >> n;
    vector<int> v, v1;
    int max1 = 0, max1n = 0, max2 = 0, max2n = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        if (max1 < temp)
        {
            max1n = i;
        }
        max1 = max(max1, temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v1.push_back(temp);
        if (max2 < temp)
        {
            max2n = i;
        }
        max2 = max(max2, temp);
    }
    if (max1 == max2 && (v[max1n] == v1[max1n] || v[max2n] == v1[max2n]))
    {
        debug(max1n, max2n, v[max1n], v1[max1n], v[max2n], v1[max2n]);
        cout << max1 * max2;
        return;
    }
    else
    {
        if (max1 >= max2)
            for (int i = 0; i < n; i++)
            {
                if (v[i] < v1[i])
                {
                    v[i] = v[i] + v1[i];
                    v1[i] = v[i] - v1[i];
                    v[i] -= v1[i];
                }
            }
        else
            for (int i = 0; i < n; i++)
            {
                if (v[i] > v1[i])
                {
                    v[i] = v[i] + v1[i];
                    v1[i] = v[i] - v1[i];
                    v[i] -= v1[i];
                }
            }
        max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++)
        {
            max1 = max(max1, v[i]);
            max2 = max(max2, v1[i]);
        }
        cout << max1 * max2;
    }
}

// clang-format off
int32_t main()
{
	#ifndef LOCAL
	free;
	#endif
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
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout<< time_span.count();
}
