#include <iostream>    
#include <algorithm> 
#include <vector>

using namespace std;

pair<int, int> findPositions(vector<int>const& a_input, int a_target)
{
  pair<int, int> res;
  auto fir = find (a_input.begin(), a_input.end(), a_target);
   if (fir != a_input.end())
    res.first = distance(a_input.begin(), fir);
   else
    res.first = -1;

    auto sec = find (a_input.rbegin(), a_input.rend(), a_target);
   if (sec != a_input.rend())
    res.second = a_input.size() - distance(a_input.rbegin(), sec) -1;
   else
    res.second = -1;
    return res;
}

int main () 
{
   vector<int> input = {1,3,4,4,4,4,4,4,7,8};
    pair<int, int> result = findPositions(input, 4);
    cout << result.first << ", " << result.second << endl;
    return 0;
}