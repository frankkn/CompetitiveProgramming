#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cnt;

vector<string> ans;

void hanoi(int n, string A, string B, string C)
{
  if(n == 0)
  {
  	return;
  }
  cnt++;
  hanoi(n-1,A,C,B);
  string s = A +" " +C;
  ans.push_back(s);
  hanoi(n-1,B,A,C);
}

int main()
{
  int n;
  cin >> n;
  hanoi(n,"1","2","3");
  cout << cnt << "\n";
  for(const auto& a_i:ans){
  	cout << a_i << "\n";
  }
  return 0;
}