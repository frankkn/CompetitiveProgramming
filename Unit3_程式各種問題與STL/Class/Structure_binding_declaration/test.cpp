#include <iostream>
#include <tuple>
#include <utility>
using namespace std;

int main() {
  {
    int A[2] = {1, 2};
    auto [x, y] = A;
    auto &[xr, yr] = A;
    xr = 3, yr = 4;
    cout << x << ' ' << y << endl;
    cout << A[0] << ' ' << A[1] << endl;
  }
  {
    pair<int, double> P(1, 0.2);
    auto [x, y] = P;
  }
  {
    tuple<int, double, char> T(1, 0.2, 'a');
    auto [x, y, z] = T;
  }
  return 0;
}
