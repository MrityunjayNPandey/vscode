/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 08-06-2023 03:16:48
 **/
// clang-format off
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;
#define endl "\n"
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...) 73;
#define dclear(x) 73;
#endif
#define free freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("error.txt","w",stderr);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define LOG(n) 63 - __builtin_clzll(n)
const long long MAX_N = 1e6 + 7; const long long MOD = 1e9 + 7; const long long mod = 998244353; const long long INF = INT_MAX;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; //find_by_order(k), order_of_key(k)
// clang-format on
#define int long long
int Test, I, tnum;

// Credits to HealthyUG for the inspiration.
// Segment Tree with Point Updates and Range Queries
// Supports multiple Segment Trees with just a change in the Node and Update
// Very few changes required everytime

template <typename Node, typename Update> struct SegTree {
  vector<Node> tree;
  vector<long long> arr; // type may change
  int n;
  int s;
  SegTree(int a_len, vector<long long> &a) { // change if type updated
    arr = a;
    n = a_len;
    s = 1;
    while (s < 2 * n) {
      s = s << 1;
    }
    tree.resize(s);
    fill(all(tree), Node());
    build(0, n - 1, 1);
  }
  void build(int start, int end, int index) // Never change this
  {
    if (start == end) {
      tree[index] = Node(arr[start]);
      return;
    }
    int mid = (start + end) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  void update(int start, int end, int index, int query_index,
              Update &u) // Never Change this
  {
    if (start == end) {
      u.apply(tree[index]);
      return;
    }
    int mid = (start + end) / 2;
    if (mid >= query_index)
      update(start, mid, 2 * index, query_index, u);
    else
      update(mid + 1, end, 2 * index + 1, query_index, u);
    tree[index].merge(tree[2 * index], tree[2 * index + 1]);
  }
  Node query(int start, int end, int index, int left,
             int right) { // Never change this
    if (start > right || end < left)
      return Node();
    if (start >= left && end <= right)
      return tree[index];
    int mid = (start + end) / 2;
    Node l, r, ans;
    l = query(start, mid, 2 * index, left, right);
    r = query(mid + 1, end, 2 * index + 1, left, right);
    ans.merge(l, r);
    return ans;
  }
  void make_update(int index,
                   long long val) {  // pass in as many parameters as required
    Update new_update = Update(val); // may change
    update(0, n - 1, 1, index, new_update);
  }
  Node make_query(int left, int right) {
    return query(0, n - 1, 1, left, right);
  }
};

struct Node1 {
  long long val; // may change
  Node1() {      // Identity element
    val = 0;     // may change
  }
  Node1(long long p1) { // Actual Node
    val = p1;           // may change
  }
  void merge(Node1 &l, Node1 &r) { // Merge two child nodes
    val = l.val + r.val;           // may change
  }
};

struct Update1 {
  long long val;          // may change
  Update1(long long p1) { // Actual Update
    val = p1;             // may change
  }
  void apply(Node1 &a) { // apply update to given node
    a.val = val;         // may change
  }
};

// SegTree<Node1, Update1> mysegtree(n, v);
// mysegtree.make_query(l, r).val;
// mysegtree.make_update(ind, val);

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  vector<string> str(2);
  cin >> str[0] >> str[1];
  n = str[0].length();
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    if (str[0][i] == str[1][i])
      v[i] = 1;
  }
  SegTree<Node1, Update1> segm(n, v);
  int t, q;
  cin >> t >> q;
  queue<pair<int, int>> que;
  for (int i = 0; i < q; i++) {
    while (que.size() && que.front().second + t <= i) {
      if (str[0][que.front().first] != str[1][que.front().first]) {
        segm.make_update(que.front().first, 0);
        v[que.front().first] = 0;
      }
      que.pop();
    }
    int x;
    cin >> x;
    if (x == 1) {
      int val;
      cin >> val;
      val--;
      que.push({val, i});
      if (v[val] != 1) {
        segm.make_update(val, 1);
        v[val] = 1;
      }
    } else if (x == 2) {
      int c1, c2, c3, c4;
      cin >> c1 >> c2 >> c3 >> c4;
      c1--, c2--, c3--, c4--;
      swap(str[c1][c2], str[c3][c4]);
      if (v[c2] != (str[0][c2] == str[1][c2])) {
        segm.make_update(c2, (str[0][c2] == str[1][c2]));
        v[c2] = (str[0][c2] == str[1][c2]);
      }
      if (v[c4] != (str[0][c4] == str[1][c4])) {
        segm.make_update(c4, (str[0][c4] == str[1][c4]));
        v[c4] = (str[0][c4] == str[1][c4]);
      }
    } else {
      (segm.make_query(0, n).val == n) ? cout << "YES\n" : cout << "NO\n";
    }
    int qr = segm.make_query(0, n).val;
    debug(qr, v);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef SUBLIME
  free
#endif
      cout.precision(16);
  cout << fixed;
  Test = 1;
  cin >> Test;
  for (I = 1; I <= Test; I++) {
    dclear(I);
    solve();
  }
}
