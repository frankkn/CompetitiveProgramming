#include <iostream>
#include <tuple>

int main() {
  std::tuple<int, double, char> mytuple;
  mytuple = std::make_tuple(10, 2.6, 'a');

  int myint;
  char mychar;
  std::tie(myint, std::ignore, mychar) = mytuple;

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';
  return 0;
}
