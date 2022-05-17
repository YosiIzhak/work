#include <iostream>    
#include <algorithm> 
#include <array>
#include <cmath>

using namespace std;

int mySqrt(int a_num)
{
   int res = a_num;
   while(res * res > a_num)
   {
      --res;
   }
    return res;
}

int main () 
{
    int res = mySqrt(17);

    cout << res << endl;
    return 0;
}