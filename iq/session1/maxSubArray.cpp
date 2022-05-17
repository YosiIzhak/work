#include <iostream>    
#include <algorithm> 
#include <vector>
#include <cmath>

using namespace std;


int maxSub(vector<int>& a_vector)
{
   int sum = 0, max = 0;
   for (int i = 0; i < a_vector.size(); ++i)
   {
       sum += a_vector[i];
       if (sum < 0)
       {
           sum = 0;
       }
       if (sum > max)
       {
           max = sum;
       }
   }
   return max;
  
}

int main () 
{
    vector<int> input = {1,2,3,-5,1,6,7};
    int res = maxSub(input);
    cout << res << endl;
    return 0;
}