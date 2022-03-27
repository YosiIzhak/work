#include <iostream>    
#include <algorithm> 

using namespace std;
#define INT_SIZE 32
int countPairs(int a_number)
{
    int count = 0;
    for (int i = 0; i < INT_SIZE;)
    {
        if ((a_number>>i&1) && (a_number>>i+1&1))
        {
           count++;
        }
       i = i+2;
    }
    return count;
}
int main () 
{
    int num = 12;
   
    int res = countPairs(num);
    
          cout << res << " ";
   
    return 0;
}