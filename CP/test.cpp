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

// Function to check if there are any cyclic dependencies
bool hasCyclicDependency(const vector<vector<int>> &adj, int v,
                         vector<bool> &visited, vector<bool> &recStack) {
  if (!visited[v]) {
    visited[v] = true;
    recStack[v] = true;

    for (const int &neighbor : adj[v]) {
      if (!visited[neighbor] &&
          hasCyclicDependency(adj, neighbor, visited, recStack))
        return true;
      else if (recStack[neighbor])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

// Function to generate a random test case
void generateTestCase(int &n, int &m, int &k, vector<int> &h,
                      set<pair<int, int>> &dependencies) {
  n = 1 + rand() % 200000;
  m = rand() % (n * (n - 1) / 2 + 1);
  k = 1 + rand() % 1000000000;

  h.clear();
  for (int i = 0; i < n; i++) {
    h.push_back(rand() % k);
  }

  // Generate a random directed acyclic graph (DAG) to ensure no cyclic
  // dependencies
  vector<vector<int>> adj(n);
  dependencies.clear();
  while (dependencies.size() < m) {
    int a = 1 + rand() % n;
    int b = 1 + rand() % n;
    if (a != b &&
        find(adj[a - 1].begin(), adj[a - 1].end(), b) == adj[a - 1].end()) {
      adj[a - 1].push_back(b);
      dependencies.insert({a, b});
    }
  }

  // Validate that the generated graph is acyclic
  vector<bool> visited(n, false);
  vector<bool> recStack(n, false);
  for (int i = 0; i < n; i++) {
    if (!visited[i] && hasCyclicDependency(adj, i, visited, recStack)) {
      // If a cyclic dependency is found, regenerate the test case
      generateTestCase(n, m, k, h, dependencies);
      return;
    }
  }

  // Write the test case to the input file
  cout << n << " " << m << " " << k << endl;
  for (int i = 0; i < n; i++) {
    cout << h[i] << " ";
  }
  cout << endl;
  for (const auto &dep : dependencies) {
    cout << dep.first << " " << dep.second << endl;
  }
}

// Function to generate expected output for a test case
int generateExpectedOutput(int n, int m, int k, const vector<int> &h,
                           const set<pair<int, int>> &dependencies) {
  // Your solution to calculate the expected output goes here
  // Implement the logic to solve the problem for this test case

  // Replace this with the actual logic to calculate the expected output
  int ans = 0;

  return ans;
}

signed main() {
  free;
  int t = 300;
  cout << t << endl;

  for (int i = 0; i < t; i++) {
    int n, m, k;
    n = rand(1, 200);
    m = rand(1, 200);
    k = rand(n, 1000000);
    vector<int> h;
    set<pair<int, int>> dependencies;

    generateTestCase(n, m, k, h, dependencies);
    cout << generateExpectedOutput(n, m, k, h, dependencies) << endl;
  }
}