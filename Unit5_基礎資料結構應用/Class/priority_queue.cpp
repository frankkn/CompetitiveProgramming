#include <iostream>
#include <queue>
using namespace std;

struct CMP 
{
  bool operator()(int a, int b) { return a > b; }
};

int main() 
{
  priority_queue<int> PQ1;
  priority_queue<int, vector<int>, CMP> PQ2;
  for (int i = 0; i < 5; ++i) {
    PQ1.emplace(i);
    PQ2.emplace(i);
  }
  cout << PQ1.top() << ' ' << PQ2.top() << '\n';
  return 0;
}