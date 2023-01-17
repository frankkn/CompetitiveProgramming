#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
vector<bool> is_prime;
void sieve(int n) {
  primes.clear();
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < n; ++i) {
    if (is_prime[i]) primes.emplace_back(i);
    for (auto p : primes) {
      if (1LL * i * p > n) break;
      is_prime[i * p] = false;
      if (i % p == 0) break;
    }
  }
}
