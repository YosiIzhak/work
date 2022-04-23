#include <iostream>
#include <stddef.h>
#include <vector>

using namespace std;

int lastIndex(vector<int>& a_vec)
{
      int index = -1;
      for (auto i = 0; i < a_vec.size(); i++)
      {
          if (a_vec[i] == 1)
          {
            index = i;
          }
      }
    return index;
}

int main () 
{
    vector<int> input = {0,1,1,1,0,0,0,0,1,0};
    
    int res =  lastIndex(input);

    cout << res << endl;
   
   return 0;
}