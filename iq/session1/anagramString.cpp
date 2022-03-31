#include <iostream>
#include <algorithm>
#include <stddef.h>
#include <unordered_map>
#include <vector>
using namespace std;
vector<vector<string> > anagramString(vector<string> a_vec)
{
   unordered_map<string, vector<string> > mp;
   vector<vector<string> > result;
    for (size_t i = 0; i < a_vec.size(); ++i)
    {
        string key = a_vec[i];
        sort(key.begin(), key.end());
        mp[key].push_back(a_vec[i]);
    }
    for(auto k : mp)
    {
        result.push_back(k.second);
    }
    return result;
}

int main () 
{
    vector<string> input = {"abc" , "bac", "tea", "pil", "lip" ,"ilp", "pli", "ipl"};
    
    vector<vector<string> > output =  anagramString(input);

    // print the output
    for (int i = 0; i < output.size(); i++)
    {
        if (output[i].size() > 0)
        {
            cout << " ( ";
            for (int j = 0; j < output[i].size(); j++)
            {
                 cout << output[i][j] << " ";
            }
            cout << ")";
        }
        cout<<endl;
    }
    return 0;
}