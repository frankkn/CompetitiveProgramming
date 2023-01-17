#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

vector<string> gray_code(int n)
{
  vector<string> v;
  if(n == 1)
  {
  	v.push_back("0");
    v.push_back("1");
    return v;
  }
  
  vector<string> v1;
  v1 = gray_code(n-1);
  
  for(int i = 0; i < v1.size(); ++i)
  {
  	v.push_back('0'+v1[i]);
  }
  
  for(int i = v1.size()-1; i >= 0; --i)
  {
  	v.push_back('1'+v1[i]);
  }
  return v;

}

int main()
{
  cin >> n;
  vector<string> v;
  v = gray_code(n);
  for(const auto& v_i:v)
  {
    cout << v_i << "\n";
  }

  return 0;
}