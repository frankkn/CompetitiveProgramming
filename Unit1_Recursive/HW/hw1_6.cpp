#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> g(25);
int tmp_offices[5];
int officeIdx = 0;
int best_offices[5];

int min_sum;

void cal(int areaNum)
{

  if(officeIdx < 5)
  {
    for(int i = areaNum; i < 25; ++i)
    {
      tmp_offices[officeIdx++] = i;
      cal(i+1);
      --officeIdx;
    }
  }
  else
  {
    int sum = 0;
	for(int i = 0; i < 25; ++i){
      if(g[i] > 0)
      {
        int min_dist = INT_MAX;
      	for(int j = 0; j < 5; ++j)
        {
          min_dist = min(min_dist, g[i]*(abs(tmp_offices[j]/5 - i/5) + abs(tmp_offices[j]%5 - i%5)));
        }
        sum += min_dist;
      }
    }
    if(sum < min_sum)
    {
      min_sum = sum;
      for(int i = 0; i < 5; ++i)
      {
        best_offices[i] = tmp_offices[i];
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int areas;
    cin >> areas;
    fill(g.begin(), g.end(), 0);
    while(areas--)
    {
      int x, y, pop;
      cin >> x >> y >> pop;
      g[x*5+y] = pop;
    }
	min_sum = INT_MAX;
    cal(0);
    
    for(int i = 0; i < 5; ++i){
      cout << best_offices[i] << " \n"[i==4];
    }
    

  }

  return 0;
}
