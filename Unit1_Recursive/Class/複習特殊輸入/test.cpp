#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string str;
  while(getline(cin, str))
  {
    for(char& c: str)
    {
      if(!isdigit(c))
      {
        c = ' ';
      }    
    }
  
    stringstream ss(str);
    int a {}, sum {};

    while(ss >> a)
    {
      sum += a;
    }
    cout << sum << "\n";
    sum = 0;
  }

  return 0;
}