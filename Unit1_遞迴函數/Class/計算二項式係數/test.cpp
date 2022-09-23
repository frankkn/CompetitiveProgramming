#include <iostream>
using namespace std;

int C(int n, int k)
{
  if(k == 0 || k == n)
  {
    return 1;
  }
  return C(n-1, k-1)+ C(n-1, k);
}

int main()
{
  cout << C(4,2);
  return 0;
}