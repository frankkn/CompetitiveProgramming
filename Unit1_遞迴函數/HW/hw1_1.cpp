#include <iostream>
using namespace std;

void in(int i);

void out(int i)
{
  if(i > 2) out(i-2);
  printf("Move ring %d out\n", i);
  if(i > 2) in(i-2);
  if(i > 1) out(i-1);
}

void in(int i)
{
  if(i > 1) in(i-1);
  if(i > 2) out(i-2);
  printf("Move ring %d in\n", i);
  if(i > 2)	in(i-2);
}
  

int main()
{
  int n;
  cin >> n;
  out(n);
  return 0;
}