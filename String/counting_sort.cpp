#include <iostream>
#include <vector>
using namespace std;

vector<unsigned> counting_sort(const vector<unsigned> &Arr, unsigned k) {
  vector<unsigned> Bucket(k, 0);
  for (auto x : Arr)
    ++Bucket[x];
  vector<unsigned> Ans;
  for (unsigned x = 0; x < k; ++x)
    while (Bucket[x]--)
      Ans.emplace_back(x);
  return Ans;
}

vector<unsigned> counting_sort(const vector<unsigned> &Arr, unsigned k) {
  vector<unsigned> Bucket(k, 0);
  for (auto x : Arr)
    ++Bucket[x];
  partial_sum(Bucket.begin(), Bucket.end(), Bucket.begin());
  vector<unsigned> Ans(Arr.size());
  for (auto Iter = Arr.rbegin(); Iter != Arr.rend(); ++Iter)
    Ans[--Bucket[*Iter]] = *Iter; 
  return Ans;
}

