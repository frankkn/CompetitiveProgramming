#include <iostream>
#include <functional>
using namespace std;

pair<int, int> search(int L, int R, function<bool(int)> check) {
  for (int i = L; i <= R; ++i)
    if (check(i) == false)
      return {i - 1, i};
  return {R, R + 1};
}

int main() {
  int arr[] = {2, 3, 3, 7, 7, 7, 9, 9, 12, 12};
  auto check = [&](int idx) { return arr[idx] < 7; };
  auto [a, b] = search(0, 9, check);
  cout << a << ' ' << b << '\n';
  return 0;
}
