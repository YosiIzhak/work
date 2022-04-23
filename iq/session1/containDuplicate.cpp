#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

const int N = 10;
bool containDuplicate(array<int, N>const& a_array)
{
   unordered_map<long, int> mp;
 
    for (size_t i = 0; i < N; ++i)
    {
        mp[a_array[i]]++;
    }
    
    int max = 0;
   
    for(auto k : mp)
    {
        
        if (k.second > 1)
        {
            return true;
        }
    }
    return false;
}

int main () 
{
    array<int,N> input = {1,2,3,9,8,4,5,0,7,6};
    
    bool res =  containDuplicate(input);
    
    cout << res << endl;
  
   
   return 0;
}