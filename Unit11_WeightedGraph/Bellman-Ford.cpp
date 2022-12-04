#include <iostream>
#include <vector>
#include <queue>
#define INF 1e+9
using namespace std;

struct Edge {
  int u, v;
  int cost;
};

vector<long long> bellman_ford(vector<Edge> E, int n, int S) 
{
  vector<long long> d(n, INF); // 假設點的編號為 0 ~ n-1
  d[S] = 0; // 起點設 0
  auto relax = [&](Edge e) {
    if (d[e.v] > d[e.u] + e.cost) 
    {
      d[e.v] = d[e.u] + e.cost;
      return true;
    }
    return false;
  };
  for (;;) {
    bool update = false;
    for (auto &e : E)
      update |= relax(e);
    if (!update) break;
  }
  return d;
}

vector<long long> bellman_ford(vector<Edge> E, int n, int S) 
{
  vector<long long> d(n, INF); // 假設點的編號為 0 ~ n-1
  d[S] = 0; // 起點設 0
  auto relax = [&](Edge e) { 
    if (d[e.v] > d[e.u] + e.cost) 
    {
      d[e.v] = d[e.u] + e.cost;
      return true;
    }
    return false;
  };
  for (int t = 1; t <= n - 1; ++t) {
    for (auto &e : E) relax(e);
  }
  return d;
}

vector<long long> bellman_ford(vector<Edge> E, int n, int S) {
  vector<long long> d(n, INF); // 假設點的編號為 0 ~ n-1
  d[S] = 0; // 起點設 0
  auto relax = [&](Edge e) { 
    if (d[e.v] > d[e.u] + e.cost) 
    {
      d[e.v] = d[e.u] + e.cost;
      return true;
    }
    return false;
  };
  for (int t = 1; t <= n; ++t) {
    bool update = false;
    for (auto &e : E)
      update |= relax(e);
    if (t == n && update) return {};
  }
  return d;
}

