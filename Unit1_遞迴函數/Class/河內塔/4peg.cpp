#include <iostream>
using namespace std;

int step = 0;

void hanoi(int n, char from, char aux1, char aux2, char to) // A:from B:aux1 C:aux2 D:to
{
  if(n == 0)
  {
    return;
  }
  if(n == 1) 
  {
    step += 1;
    printf("Move ring %d from %c to %c\n", n, from, to);
    return;
  }
  step += 3;
  hanoi(n-2, from, aux2, to, aux1); 
  printf("Move ring %d from %c to %c\n", n-1, from, aux2);
  printf("Move ring %d from %c to %c\n", n, from, to);
  printf("Move ring %d from %c to %c\n", n-1, aux2, to);
  hanoi(n-2, aux1, from, aux2, to);
  return;
}

int main()
{
  int n = 3; // # of disks
  hanoi(n, 'A', 'B', 'C', 'D');
  cout << step;
  return 0;
}
