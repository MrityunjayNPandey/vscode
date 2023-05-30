class Solution {
public:
  long long find(char t) {
    vector<long long> start(n, 0), end(n, 0);
    int f = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == t) {
          f = 1;
          start[i] = start[i - 1];
      } else {
          if (f == 0)
            start[i] = start[i - 1] + 1;
          else {
            f = 0;
            start[i] = start[i - 1] + 2 * i + 1;
        }
      }
    }
    f = 0;
    reverse(s.begin(), s.end());
    for (int i = 1; i < n; i++) {
      if (s[i] == t) {
        f = 1;
          end[i] = end[i - 1];
      } else {
          if (f == 0)
            end[i] = end[i - 1] + 1;
          else {
            f = 0;
            end[i] = end[i - 1] + 2 * i + 1;
        }
      }
    }
    reverse(end.begin(), end.end());
    reverse(s.begin(), s.end());
    long long cost = min(start[n - 1], end[0]);
    for (int i = 0; i < n - 1; i++) {
      cost = min(cost, start[i] + end[i + 1]);
    }
    return cost;
  };
  long long minimumCost(string s) {
    int n = s.size();
    return min(find('0'), find('1'));
  }
};