#include <iostream>
#include <vector>
using namespace std;

class DisjointSet 
{
  vector<int> parent;
  int find_root(int x) 
  {
    if (x == parent[x]) return x;
    int root = find_root(parent[x]);
    return parent[x] = root; // 路徑壓縮
  }

public:
  DisjointSet(size_t n):parent(n + 1) { init(); }
  void init() 
  {
    for (size_t i = 0; i < parent.size(); ++i)
      parent[i] = i;
  }
  bool Same(int a, int b) { return find_root(a) == find_root(b); }
  void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};

// int parent[MAXN];
// void init(int n) {
//   for (int i = 0; i < n; ++i) {
//     parent[i] = i;
//   }
// }

// int find_root(int x) {
//   if (x == parent[x])
//     return x;
//   // return find_root(parent[x]);
//   int root = find_root(parent[x]);
//   return parent[x] = root;
// }

// bool Same(int a, int b) {
//   return find_root(a) == find_root(b);
// }

// void Union(int a, int b) {
//   parent[find_root(a)] = find_root(b);
// }

// void Union(int a, int b) {
//   int pa = find_root(a), pb = find_root(b);
//   if (rank[pa] > rank[pb])
//     swap(pa, pb);
//   parent[pa] = pb;
//   if (rank[pa] == rank[pb])
//     ++rank[pb];
// }
