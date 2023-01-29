/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 05-01-2023 21:15:26
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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// clang-format on
#define int long long
int Test, I, tnum;

void swap(vector<int> &arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
pair<int, int> minSwaps(vector<int> arr, int N) {
  int ans = 0, ans1 = 0;
  vector<int> temp = arr;

  // Hashmap which stores the
  // indexes of the input array
  map<int, int> h;

  sort(temp.begin(), temp.end());
  for (int i = 0; i < N; i++) {
    h[arr[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    // This is checking whether
    // the current element is
    // at the right place or not
    if (arr[i] != temp[i]) {
      ans++;
      int init = arr[i];

      // If not, swap this element
      // with the index of the
      // element which should come here
      swap(arr, i, h[temp[i]]);
      if (abs(i - h[temp[i]]) == 1) {
        ans1++;
      }
      // Update the indexes in
      // the hashmap accordingly
      h[init] = h[temp[i]];
      h[temp[i]] = i;
    }
  }
  return {ans, ans1};
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  auto [x, y] = minSwaps(v, n);
  debug(x, y)
  if (y) {
    cout << x - 1;
  } else
    cout << x + 1;
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
    cout << endl;
  }
}

/*
Did I ever tell you what the definition of insanity is?
Insanity is doing the exact... same fucking thing... over and over again
expecting... shit to change... That. Is. Crazy. The first time somebody told me
that, I dunno, I thought they were bullshitting me. The thing is... He was
right. And then I started seeing, everywhere I looked, everywhere I looked all
these fucking pricks, everywhere I looked, doing the exact same fucking thing...
over and over and over and over again thinking 'this time is gonna be different'
no, no, no please... This time is gonna be different, I'm sorry, I don't like...
The way...

Okay, Do you have a fucking problem in your head, do you think I am bullshitting
you, do you think I am lying? Fuck you! Okay? Fuck you!...
*/
