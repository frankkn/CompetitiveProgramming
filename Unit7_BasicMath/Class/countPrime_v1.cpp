#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> is_prime;
void sieve(int n) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  //for (int i = 2; i <= n; ++i)
  for (int i = 2; i * i <= n; ++i)
    if (is_prime[i])
      //for (int j = i * 2; j <= n; j += i)
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
}

vector<int> primes;
int solve(int a, int b){
  auto L = lower_bound(primes.begin(), primes.end(), a);
  auto U = upper_bound(primes.begin(), primes.end(), b);
  return U - L;
}

vector<bool> is_prime;
vector<int> prefix_sum;
int solve(int a, int b) { return prefix_sum[b] - prefix_sum[a - 1]; }

