#include <bits/stdc++.h>
using namespace std;
#define free                                                                   \
  freopen("input.txt", "r", stdin);                                            \
  freopen("input.txt", "w", stdout);                                           \
  freopen("error.txt", "w", stderr);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
// Random n numbers between l and r
void num(int l, int r, int n) {
  for (int i = 0; i < n; ++i) {
    cout << rand(l, r) << endl;
  }
}

// Random n real numbers between l and r with dig decimal places
void real(int l, int r, int dig, int n) {
  for (int i = 0; i < n; ++i) {
    cout << rand(l, r) << "." << rand(0, pow(10, dig) - 1) << " ";
  }
}
// Random n strings of length l
void str(int l, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      // int v = rand(1, 150);
      // if (v % 3 == 0)
      cout << (char)rand('a', 'z');
      // else if (v % 3 == 1)
      //     cout << (char)rand('A', 'Z');
      // else
      // v[j] = rand(1, 104);
    }
    // sort(v.begin(), v.end());
  }
  cout << endl;
}
// Random n strings of max length l
void strmx(int mxlen, int n) {
  for (int i = 0; i < n; ++i) {
    int l = rand(1, mxlen);
    for (int j = 0; j < l; ++j) {
      int v = rand(1, 150);
      if (3 % 3 == 0)
        cout << (char)rand('a', 'z');
      else if (v % 3 == 1)
        cout << (char)rand('A', 'Z');
      else
        cout << rand(0, 9);
    }
    cout << " ";
  }
}
// Random tree of n nodes
void tree(int n) {
  int prufer[n - 2];
  for (int i = 0; i < n; i++) {
    prufer[i] = rand(1, n);
  }
  int m = n - 2;
  int vertices = m + 2;
  int vertex_set[vertices];
  for (int i = 0; i < vertices; i++)
    vertex_set[i] = 0;
  for (int i = 0; i < vertices - 2; i++)
    vertex_set[prufer[i] - 1] += 1;
  int j = 0;
  for (int i = 0; i < vertices - 2; i++) {
    for (j = 0; j < vertices; j++) {
      if (vertex_set[j] == 0) {
        vertex_set[j] = -1;
        cout << (j + 1) << " " << prufer[i] << '\n';
        vertex_set[prufer[i] - 1]--;
        break;
      }
    }
  }
  j = 0;
  for (int i = 0; i < vertices; i++) {
    if (vertex_set[i] == 0 && j == 0) {
      cout << (i + 1) << " ";
      j++;
    } else if (vertex_set[i] == 0 && j == 1)
      cout << (i + 1) << "\n";
  }
}

// Prints the array
void printArr(int a[], int n) {
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  printf("\n");
}

// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n) {
  // if size becomes 1 then prints the obtained
  // permutation
  if (size == 1) {
    cout << n << endl;
    printArr(a, n);
    return;
  }

  for (int i = 0; i < size; i++) {
    heapPermutation(a, size - 1, n);

    // if size is odd, swap 0th i.e (first) and
    // (size-1)th i.e (last) element
    if (size % 2 == 1)
      swap(a[0], a[size - 1]);

    // If size is even, swap ith and
    // (size-1)th i.e (last) element
    else
      swap(a[i], a[size - 1]);
  }
}

signed main() {
  free;
  int t = 20000;
  cout << t << endl;
  int k = 1, p = 0;
  for (int i = 1; i < t; i++) {
    string str = to_string(i);
    int sum = 0;
    for (auto i : str)
      sum += i - '0';
    int x = 1;
    while (x < sum) {
      cout << i << " " << x << endl;
      x++;
      p++;
      if (p == 20000)
        break;
    }
    if (p == 20000)
      break;
  }
}