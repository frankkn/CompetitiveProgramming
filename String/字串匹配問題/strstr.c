#include <stdio.h>
#include <string.h>

int main() {
  char Tc[] = "This is C-style string with an Egg.";
  char Sc[] = "Egg";
  char* res = strstr(Tc, Sc);
  if (res != NULL) {
    printf("found %s at %d\n", Sc, res - Tc);
  }
  return 0;
}