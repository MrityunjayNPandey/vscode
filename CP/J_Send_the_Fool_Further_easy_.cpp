// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef joKer
#include "algo/debug.h"
#else
#define debug(...) 
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
#define ios ios_base::sync_with_stdio(false); cin.tie(0);
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9+7; const long long mod = 998244353;
#define int long long
int I;

                    // do something, stay focused
                    // look for stupid bugs
                    // guess, slow, stress
                    // don't overgeneralize
                    // don't rush
                        
                    // 1. Understand the problem
                    // 2. Devise a plan
                    // 3. Carry out the plan
                    // 4. Look back
                        
                    // don't waste time on standings
                        
                    // SOLVE THE PROBLEM OR DIE TRYING
                    // THE SOLUTION IS ALWAYS SIMPLE
                    // THE CODE IS ALWAYS SHORT

// clang-format on

int ans = 0, maxans=0;

// DFS, time complexity of O(V+E)
// Remember to clear the maps in main() if multiple test cases exist.
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> adj_list; // adjacency list
map<pair<int, int>, int> adj_weight;      // to add weights on edges
void DFS(int current)
{
    visited[current] = true;
    for (int next_vertex : adj_list[current])
        if (!visited[next_vertex])
        {
            ans += adj_weight[{current, next_vertex}];
            maxans=max(ans, maxans);
            DFS(next_vertex);
            ans=0;
        }
}

void solve()
{
    int n = 0, k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        adj_list[p].push_back(q);
        adj_list[q].push_back(p);
        adj_weight[{p, q}] = r;
        adj_weight[{q, p}] = r;
    }
    DFS(0);
    cout << maxans;
}

// clang-format off
int32_t main()
{
    ios;
    int Test = 1;
    // cin >> Test;
    for (I = 1; I <= Test; I++)
    {
        #ifdef joKer
        cerr << "-------" << I << "-------" << endl;
        #endif
        solve();
        cout << endl;
    }
}
