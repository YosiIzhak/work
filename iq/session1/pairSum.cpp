#include <iostream>    
#include <algorithm> 
#include <array>
#include <unordered_map>

using namespace std;

template <size_t N>
int pairSum(array<int, N>& a_array, int a_number)
{
    unordered_map<int, size_t> map;
    size_t counter = 0;
    
    for (auto e : a_array)
    {
        int delta = a_number - e;
        if(map.find(delta) != map.end())
        {
            counter += map[delta];
        }
        ++map[e];
    }
    return counter;
}

int main () 
{
   array<int, 10> myArray = {1,9,1};
   int res = pairSum(myArray, 10);
    cout << "res " << res << endl;

    return 0;
}