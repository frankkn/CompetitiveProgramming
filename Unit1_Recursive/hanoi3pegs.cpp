/*
### input: 
3

### output:
Move ring 1 from A to C  
Move ring 2 from A to B  
Move ring 1 from C to B  
Move ring 3 from A to C  
Move ring 1 from B to A  
Move ring 2 from B to C  
Move ring 1 from A to C  
*/

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