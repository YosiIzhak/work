#include <iostream>    
#include <algorithm> 
#include <array>
#include <cmath>

using namespace std;

int divideTwo(int a_dividend, int a_divisor)
{
   int sum = 0, count = 0;
   while(abs(sum) <= abs(a_dividend))
   {
       sum += a_divisor;
       if ((a_dividend > 0 && a_divisor > 0) || (a_dividend < 0 && a_divisor < 0))
       count++;
       else
       count--;
   }
   if ((a_dividend > 0 && a_divisor > 0) || (a_dividend < 0 && a_divisor < 0))
    return count - 1;
   else
    return count + 1;
}

int main () 
{
    int res = divideTwo(-7, 3);
    cout << res << endl;
    return 0;
}