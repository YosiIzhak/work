#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <unordered_map>
#include <vector>
using namespace std;
vector<long> mostFrequency(vector<long> a_vec)
{
   unordered_map<long, int> mp;
   vector<long> result;
  
    for (size_t i = 0; i < a_vec.size(); ++i)
    {
        mp[a_vec[i]]++;
    }
    
    int max = 0;
   
    for(auto k : mp)
    {
        cout << k.first << endl;
        if (k.second > max)
        {
            result.clear();
            result.push_back(k.first);
            max = k.second;
           // cout << max <<' ' << k.first << endl;
        }
        
        else if (k.second == max)
        {
            result.push_back(k.first);
        }
        
    }
    return result;
}

int main () 
{
    vector<long> input = {1,2,3,4,4,4,5,5,5,6,7,7,8};
    
    vector<long > output =  mostFrequency(input);

   for (int j = 0; j < output.size(); j++)
   {
        cout << output[j] << " ";
   }
   cout << endl;
   
   return 0;
}