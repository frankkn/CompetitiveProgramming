
// a^b
unsigned fast_pow(unsigned a, unsigned b, unsigned m) {
  unsigned ans = 1;
  while (b) {
    if (b & 1) ans = 1ULL * (ans * a) % m;
    b >>= 1;
    a = 1ULL * (a * a) % m;
  }
  return ans;
}
