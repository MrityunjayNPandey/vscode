/**
 *      codeforces: _joKer_0
 *      codechef:  joker_0000
 *      created: 27-02-2023 21:32:49
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
const char MAX_CHAR = 26;
// Function to count frequency of each char in the
// string. freq[0] for 'a',...., freq[25] for 'z'
void countFreq(string str, int freq[], int len) {
  for (int i = 0; i < len; i++)
    freq[str.at(i) - 'a']++;
}

// Cases to check whether a palindr0mic
// string can be formed or not
bool canMakePalindrome(int freq[], int len) {
  // count_odd to count no of
  // chars with odd frequency
  int count_odd = 0;
  for (int i = 0; i < MAX_CHAR; i++)
    if (freq[i] % 2 != 0)
      count_odd++;

  // For even length string
  // no odd freq character
  if (len % 2 == 0) {
    if (count_odd > 0)
      return false;
    else
      return true;
  }

  // For odd length string
  // one odd freq character
  if (count_odd != 1)
    return false;

  return true;
}

string findOddAndRemoveItsFreq(int freq[]) {
  string odd_str = "";
  for (int i = 0; i < MAX_CHAR; i++) {
    if (freq[i] % 2 != 0) {
      freq[i]--;
      odd_str = odd_str + (char)(i + 'a');
      return odd_str;
    }
  }
  return odd_str;
}

string findPalindromicString(string str) {
  int len = str.length();

  int freq[MAX_CHAR] = {0};
  countFreq(str, freq, len);

  if (!canMakePalindrome(freq, len))
    return "No Palindromic String";

  // Assigning odd freq character if present
  // else empty string.
  string odd_str = findOddAndRemoveItsFreq(freq);

  string front_str = "", rear_str = " ";

  // Traverse characters in increasing order
  for (int i = 0; i < MAX_CHAR; i++) {
    string temp = "";
    if (freq[i] != 0) {
      char ch = (char)(i + 'a');

      // Divide all occurrences into two
      // halves. Note that odd character
      // is removed by findOddAndRemoveItsFreq()
      for (int j = 1; j <= freq[i] / 2; j++)
        temp = temp + ch;

      // creating front string
      front_str = front_str + temp;

      // creating rear string
      rear_str = temp + rear_str;
    }
  }
  return (front_str + odd_str + rear_str);
}

void solve() {
  int n = 0, m = 0, k = 0, ans = 0, cnt = 0, sum = 0;
  string str;
  cin >> str;
  multiset<char> mltst;
  map<char, int> mp;
  for (int i = 0; i < str.length(); i++) {
    mltst.insert(str[i]), mp[str[i]]++;
  }
  n = str.length();
  vector<char> v(n, '.');
  int i = 0, j = n - 1;
  if (mp.size() == 2 && (*mp.begin()).second & 1 == 1) {
    while (mltst.size()) {
      k++;
      if (k & 1) {
        v[i] = *mltst.rbegin();
        mltst.erase(prev(mltst.end()));
        i++;
      } else {
        v[j] = *mltst.rbegin();
        mltst.erase(prev(mltst.end()));
        j--;
      }
    }
    debug(v);
    string astr;
    for (int i = 0; i < n; i++) {
      astr += v[i];
    }
    string rastr = astr;
    reverse(all(rastr));
    if (findPalindromicString(str) == "No Palindromic String") {
      cout << max(astr, rastr);
    } else
      cout << min(max(astr, rastr), findPalindromicString(str));
    return;
  }
  k = 0;
  debug(mltst);
  char init = *mltst.begin();
  i = 0, j = n - 1;
  while (mltst.size()) {
    k++;
    if (k & 1) {
      v[i] = *mltst.begin();
      mltst.erase(mltst.begin());
      if (v[i] != v[j] && v[j] != '.') {
        while (mltst.size()) {
          i++;
          v[i] = *mltst.begin();
          mltst.erase(mltst.begin());
        }
      }
      i++;
     debug(v)
    } else {
      v[j] = *mltst.begin();
      mltst.erase(mltst.begin());
      if (v[i-1] != v[j] && v[i-1] != '.') {
        while (mltst.size()) {
          j--;
          v[j] = *mltst.begin();
          mltst.erase(mltst.begin());
        }
      }
      j--;
     debug(v)
    }
  }
  debug(v);
  string astr;
  for (int i = 0; i < n; i++) {
    astr += v[i];
  }
  string rastr = astr;
  reverse(all(rastr));
  cout << max(astr, rastr);
  return;
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
