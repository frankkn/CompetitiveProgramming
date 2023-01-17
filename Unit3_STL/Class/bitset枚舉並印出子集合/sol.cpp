#include <bitset>
#include <iostream>
using namespace std;

int main() {
  const int n = 4;
  for (int i = 0; i < (1 << n); ++i) {
    cout << bitset<n>(i) << endl;
  }
  return 0;
}
