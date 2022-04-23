#include <iostream>

#include <stddef.h>

#include <vector>

using namespace std;

vector<int> removeElements(vector<int>& a_vec, int val)
{
      for (auto i = 0; i < a_vec.size(); i++)
      {
          if (a_vec[i] == val)
          {
            a_vec.erase(a_vec.begin() + i);
            --i;
          }
      }
    return a_vec;
}

int main () 
{
    vector<int> input = {1,2,3,4,4,4,5,5,5,6,7,7,8};
    
    vector<int> output =  removeElements(input, 5);

   for (int j = 0; j < output.size(); j++)
   {
        cout << output[j] << " ";
   }
   cout << endl;
   
   return 0;
}