#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <vector>


using namespace std;


vector<vector<int> > permutation(vector<int>& a_nums)
{
   if(a_nums.size() <= 1)
   {
       return {a_nums};
   }
    vector<vector<int> > res;
    
    for(int i = 0; i < a_nums.size(); ++i)
    {
        vector<int> vec(a_nums.begin(), a_nums.end());
        vec.erase(vec.begin() + i);
        auto result = permutation(vec);

        for(int j = 0; j < result.size(); ++j)
        {
            vector<int> temp = result[j];
            temp.insert(temp.begin(), a_nums[i]);
            res.push_back(temp);
        }
    }
    return res;
}

int main () 
{
    vector<int> input = {1,2,3, 4};
    vector<vector<int> > res = permutation(input);
    
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    
   return 0;
}