#include <algorithm>
#include <iostream>
#include <vector>
#include "../Unit9_DisjointSet/DS.cpp"
using namespace std;

struct Edge
{
  int u, v, cost;
  bool operator<(const Edge &other) const 
  {
    return cost < other.cost;
  }
};

vector<Edge> E;
int main()
{
  int n, m;
  cin >> n >> m;
  E.resize(m);
  for (int i = 0; i < m; ++i) 
  {
    cin >> E[i].u >> E[i].v >> E[i].cost;
  }
  return 0;
}

long long MST(int n) 
{
  sort(E.begin(), E.end());
  DisjointSet DS(n);
  long long ans = 0;
  int cnt = 0;
  for (auto &e : E) 
  {
    if (DS.Same(e.u, e.v)) continue;
    DS.Union(e.u, e.v);
    ans += e.cost;
    ++cnt;
  }
  if (cnt < n - 1) cout << "not connected\n";
  return ans;
}
