#include <iostream>    
#include <algorithm> 
#include <array>
#include <cmath>

using namespace std;

int climb(int a_num)
{
  int first = 1;
  int second = 1;
  int temp = first + second;
  for (int i = 2; i < a_num; ++i)
  {
    first = second;
    second = temp;
    temp  = second + first;
  }
  return temp;
}

int main () 
{
    int res = climb(7);
    cout << res << endl;
    return 0;
}
 
 
