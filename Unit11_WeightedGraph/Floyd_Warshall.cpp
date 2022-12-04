#include <iostream>
#include <vector>
#include <queue>
#define INF 1e+9
using namespace std;

// for (int k = 0; k < n; ++k)
//   for (int u = 0; u < n; ++u)
//     for (int v = 0; v < n; ++v)
//       D[k + 1][u][v] = min(D[k][u][v], D[k][u][k] + D[k][k][v]);

// 空間優化
void floyd_warshall(vector<vector<long long>> &D) {
  int n = D.size(); // 假設點的編號為 0 ~ n-1
  for (int k = 0; k < n; ++k)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        D[u][v] = min(D[u][v], D[u][k] + D[k][v]);
}
