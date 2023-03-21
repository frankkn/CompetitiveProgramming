#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char Tc[] = "This is C-style string with an Egg.";
  char Sc[] = "Egg";
  if (auto res = strstr(Tc, Sc); res != nullptr) {
    cout << "found " << Sc << " at " << res - Tc << '\n';
  }
  return 0;
}
