#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <class T> void print(T &V) {
  for (auto x : V)
    cout << x << ' ';
  cout << '\n';
}

int main() {
  double V[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};
  int N = sizeof(V) / sizeof(double);
  stable_sort(V, V + N, [](int a, int b) { return a < b; });
  print(V);
  return 0;
}
