#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;   

vector<vector<string> > groupAnagrams(vector<string>& strsList) 
{
    vector<string> temp = strsList;
    vector<vector<string> > ans;
    map<string, vector<string> > mp;
    for(int i = 0; i < temp.size(); ++i)
	{
        string str = temp[i];
        sort(str.begin(), str.end());
        mp[str].push_back(temp[i]);
    }

    for(auto i:mp)
    {
        ans.push_back(i.second);
    } 
    return ans;

}
int main () {   
  
   vector<string> vec {"abc", "acb", "red", "der", "nasa", "bet"};
   vector<vector<string> > result = groupAnagrams(vec);

  for (int i = 0; i < result.size(); i++)
    {
        if (result[i].size() > 0)
        {
            cout << " ( ";
            for (int j = 0; j < result[i].size(); j++)
                cout << result[i][j] << " ";
            cout << ")";
        }
        cout<<endl;
    }
        
    return 0;   
}   