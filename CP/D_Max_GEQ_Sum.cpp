/**
*      codeforces: _joKer_0
*      codechef:  joker_0000
*      created: 31-05-2022 21:30:12
**/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 
#define print(x)
#define dclear(x)
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 31 - __builtin_clz(n)
const long long INF = 1ll << 32; const long long MAX_N = 1e6 + 7;
const long long MOD = 1e9 + 7; const long long mod = 998244353;
#define int long long
const int ninf = -1e15;

struct Node
{
    int sum;
    int prefix;
};

// // function to build the segment tree
// void build(int a[], int index, int beg, int end, Node tree[])
// {
//     if(beg == end)
//     {
//         tree[index].sum = a[beg];
//         tree[index].prefix = a[beg];
//     } else
//     {
//         int mid = (beg + end) / 2;
//         build(a, 2 * index + 1, beg, mid, tree);
//         build(a, 2 * index + 2, mid + 1, end, tree);
//         tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;
//         tree[index].prefix = max(tree[2 * index + 1].prefix, tree[2 * index + 1].sum + tree[2 * index + 2].prefix);
//     }
// }
// function to do the range query in the segment
// tree for the maximum prefix sum
int query(vector<int>& tree, int node, int ns, int ne, int qs, int qe)
{
    if(qe < ns || qs > ne) return ninf;
    if(qs <= ns && ne <= qe) return tree[node];

    int mid = ns + (ne - ns) / 2;
    int leftQuery = query(tree, 2 * node, ns, mid, qs, qe);
    int rightQuery = query(tree, 2 * node + 1, mid + 1, ne, qs, qe);
    return max(leftQuery, rightQuery);
}

void solve()
{
    int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int _n = n;
    while(__builtin_popcount(_n) != 1) _n++;
    // Prefix sums
    vector<int> prefixSum(n, 0), suffixSum(n, 0);
    prefixSum[0] = v[0];
    for(int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    suffixSum[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + v[i];
    }
    // Two max-segtrees, one on the prefix sums, one on the suffix sums
    vector<int> prefixTree(2 * _n, ninf), suffixTree(2 * _n, ninf);
    for(int i = 0; i < n; i++)
    {
        prefixTree[_n + i] = prefixSum[i];
        suffixTree[_n + i] = suffixSum[i];
    }
    for(int i = _n - 1; i >= 1; i--)
    {
        prefixTree[i] = max(prefixTree[2 * i], prefixTree[2 * i + 1]);
        suffixTree[i] = max(suffixTree[2 * i], suffixTree[2 * i + 1]);
    }
//FIND THE Previus Greater Element and the Next Greater Element for each element of the array.
    vector<int> NGE(n, -1), PGE(n, -1);
    stack<int> temp, temp1;
    for(int i = 0; i < n; i++)
    {
        if(!temp.empty())
            while(v[temp.top()] < v[i])
            {
                NGE[temp.top()] = i;
                temp.pop();
                if(temp.empty())
                    break;
            }
        temp.push(i);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        if(!temp1.empty())
            while(v[temp1.top()] < v[i])
            {
                PGE[temp1.top()] = i;
                temp1.pop();
                if(temp1.empty())
                    break;
            }
        temp1.push(i);
    }
    //since left range + a[i] + right range<a[
    //=> to print no, left range + right range > 0
    // left range and right range signify, the Maximum prefix-sum for a given range, the range given in query.

    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        int rightMax = query(prefixTree, 1, 0, _n - 1, i + 1, NGE[i] - 1) - prefixSum[i];
        int leftMax = query(suffixTree, 1, 0, _n - 1, PGE[i] + 1, i - 1) - suffixSum[i];
        if(max(leftMax, rightMax) > 0)
        {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0);
#ifdef SUBLIME
    free
#endif
        int Test = 1;
    cin >> Test;
    for(int I = 1; I <= Test; I++)
    {
        dclear(I);
        solve();
        cout << endl;
    }
}

