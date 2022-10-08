#include <bitset>
#include <iostream>
using namespace std;

int main() {
  bitset<100> BIT(712271227122LL);
  cout << BIT << endl;
  for (size_t i = 0; i < BIT.size() / 2; ++i)
    BIT[i] = 1;
  cout << BIT << endl;
  cout << (~BIT ^ bitset<100>("1101")) << endl;
  return 0;
}
