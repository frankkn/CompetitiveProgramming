#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists);

struct CMP 
{
  bool operator()(ListNode *a, ListNode *b) const { return a->val > b->val; }
};

priority_queue<ListNode *, vector<ListNode *>, CMP> PQ;
void initPQ(vector<ListNode *> &lists) {
  decltype(PQ)().swap(PQ);
  for (auto nd : lists)
    if (nd) PQ.emplace(nd);
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
  initPQ(lists);
  ListNode *root = nullptr;
  ListNode **cur = &root;
  while (PQ.size()) {
    auto nd = PQ.top();
    PQ.pop();
    *cur = nd;
    cur = &nd->next;
    if (*cur) PQ.emplace(*cur);
  }
  return root;
}
