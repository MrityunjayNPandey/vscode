#include <bits/stdc++.h>
using namespace std;
#ifdef joKer
#include "algo/debug.h"
#else
#define debug(...) 
#endif

vector<vector<pair<int, int>>> d(110);
vector<bool> u(100, 0);

int max_dfs(int v)
{
    u[v] = 1;
    int sum = 0;
    for (int i = 0; i < d[v].size(); i++)
        if (!u[d[v][i].first])
        {
            sum = max(sum, max_dfs(d[v][i].first) + d[v][i].second);
            debug(sum);
        }
    return sum;
}

int main()
{
    int n, m, k, c;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> m >> k >> c;
        d[m].push_back(make_pair(k, c));
        d[k].push_back(make_pair(m, c));
    }

    cout << max_dfs(0) << endl;
    return 0;
}
