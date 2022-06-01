//lettcode 290
#include <iostream>
#include <stddef.h>
#include <algorithm>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& a_nums) 
{
   for(size_t i = 0; i < a_nums.size(); ++i)
   {
       if (a_nums[i] == 0)
       {
           a_nums.erase(a_nums.begin() + i);
           a_nums.push_back(0);
       }
   }
}

int main () 
{
    vector<int> input = {0,1,2,3,0,4,4,3};
    moveZeroes(input);
    for (int j = 0; j < input.size(); j++)
    {
        cout << input[j] << " ";
    }
    cout << endl;
    return 0;
}