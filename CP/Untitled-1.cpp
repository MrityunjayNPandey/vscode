#include <bits/stdc++.h>
using namespace std;

int MAX_N = 40000;

vector<int> isprime(MAX_N + 1, 1), prime;
void SIEVE() {
  for (int p = 2; p <= MAX_N; p++) {
    if (isprime[p]) {
      prime.emplace_back(p);
      for (int i = p * p; i <= MAX_N; i += p) {
        isprime[i] = 0;
      }
    }
  }
}

bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  SIEVE();
  cin >> n;
  for (int i = 0; prime[i] * prime[i] <= n; i++) {
    int x = n / prime[i];
    if (isPrime(x)) {
      cout << prime[i];
      break;
    }
  }
}