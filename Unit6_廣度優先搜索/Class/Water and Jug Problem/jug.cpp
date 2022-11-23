#include <iostream>
#include <queue>
#include <set>
using namespace std;

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
  queue<pair<int, int>> Q;
  set<pair<int, int>> Visited;
  Q.emplace(0, 0);
  while (Q.size()) {
    auto [jug1, jug2] = Q.front(); Q.pop();
    if (Visited.count({jug1, jug2})) continue;
    if (jug1 + jug2 == targetCapacity) return true;
    Visited.emplace(jug1, jug2);
    Q.emplace(jug1Capacity, jug2); // jug1 倒滿
    Q.emplace(jug1, jug2Capacity); // jug2 倒滿
    Q.emplace(0, jug2); // jug1 倒光
    Q.emplace(jug1, 0); // jug2 倒光
    int jug2New = min(jug1 + jug2, jug2Capacity);
    int jug1New = min(jug1 + jug2, jug1Capacity);
    Q.emplace(jug1 + jug2 - jug2New, jug2New); // jug1 倒入 jug2
    Q.emplace(jug1New, jug1 + jug2 - jug1New); // jug2 倒入 jug1
  }
  return false;
}
