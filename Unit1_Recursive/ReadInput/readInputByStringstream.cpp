/*
### input: 
"1 2 3 4 5"  
"123 456"  
"1,4,7,9"  

### output:
15  
579  
21  
*/
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