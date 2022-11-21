#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C) // A:from B:aux C:to
{
  if(n == 0)
  {
    return;
  }
  hanoi(n-1, A, C, B);
  printf("Move ring %d from %c to %c\n", n, A, C);
  hanoi(n-1, B, A, C);
  return;
}

int main()
{
  hanoi(3, 'A', 'B', 'C');
  return 0;
}