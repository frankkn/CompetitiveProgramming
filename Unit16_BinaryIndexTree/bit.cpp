#include <vector>
using namespace std;

class BIT {
  int n;
  vector<long long> bit;
public:
  void init(int _n) {
    n = _n;
    bit.resize(n);
    for (auto &b : bit) b = 0;
  }

  long long query(int x) const {
    long long sum = 0;
    for (; x; x -= lowbit(x))
      sum += bit[x];
    return sum;
  }

  void modify(int x, int val) {
    for (; x <= n; x += lowbit(x))
      bit[x] += val;
  }
};