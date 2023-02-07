#include <iostream>
#include <tuple>
using namespace std;

int main() {
  tuple<int, double, char> mytuple;
  mytuple = make_tuple(10, 2.6, 'a');

  cout << get<0>(mytuple) << endl;
  cout << get<1>(mytuple) << endl;
  cout << get<2>(mytuple) << endl;
  return 0;
}
