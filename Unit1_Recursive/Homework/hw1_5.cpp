//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#define int long long int
using namespace std;

vector<string> m;
vector<int> a;
string s;
int n;

void mask(int i)
{
  if(i == n){
  	m.push_back(s);
    return;
  }
  s += "0";
  mask(i+1);
  s.pop_back();
  s += "1";
  mask(i+1);
  s.pop_back();
}

int cal()
{
  int set_a = 0, set_b = 0, diff = 0, min_diff = INT_MAX;
  for(const auto& m_i:m)
  {
    set_a = 0, set_b = 0;
    for(auto i = 0; i < m_i.size(); ++i)
    {
      if(m_i[i] == '0')
      {
        set_a += a[i];
      }
      else
      {
        set_b += a[i];
      }
    }
    diff = abs(set_a-set_b);
    min_diff = min_diff - diff > 0 ? diff: min_diff;
  }
  return min_diff;
}

signed main()
{
  cin >> n;
  a.resize(n);
  for(auto& a_i:a){
  	cin >> a_i;
  }
  
  mask(0);
  cout << cal();
  
  return 0;
}