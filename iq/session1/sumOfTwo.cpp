#include <iostream>
#include <algorithm>
#include <array>
#include <map>

using namespace std;   

template <size_t N>
int countPairs(array<int, N>& array1, int target)
{
    int count = 0;
    sort(array1.begin(), array1.end());
    for (int i = 0; i < array1.size(); ++i)
    {
          cout << array1[i] << " ";
    }
    auto it = array1.begin();
    auto end = array1.end();
    while(it != end)
    {
        if(*it + *end < target)
        {
            ++it;
        }
        if(*it + *end > target)
        {
            --end;
        }
         if(*it + *end == target)
        {
            count++;
            ++it;
        }
    }
    return count;
}

int main () {   
  
  const int N = 15;
  array<int, N> array  = { 2, 16, 77, 34, 50, 7,6, -20,1,12,3,10,40,60,-8 }; 
  
  int result =  countPairs(array, 13);
  cout << endl;
  cout << "result: " << result << endl;
        
    return 0;   
}   