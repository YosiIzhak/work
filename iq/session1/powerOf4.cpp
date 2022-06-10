 #include <iostream>
#include <stddef.h>
#include <vector>

using namespace std;

bool isPowerOfFour(int a_num) 
{
  double res = a_num;
  
  while(res > 4)
  {
    res /= 4;
  }
   
   if (res == 4)
   {
       return true;
   }
   else
   {
       return false;
   }
        
}

int main () 
{
   bool res = isPowerOfFour(68);
   cout << res << endl;

   return 0;
}