#include<iostream>   
#include<algorithm>   
#include<array>  
#include <stdlib.h> 
#include <unordered_map>

using namespace std;   

template <size_t N>
long mostFreuency(array<long, N>& array1)
{
    unordered_map<long, int> map;
    for (size_t i = 0; i < N; ++i)
    {
        map[array1[i]]++;
    }

    int max_count = 0;
    long res = -1;
    
    for (auto i : map) 
    {
        if (max_count < i.second)
        {
            res = i.first;
            max_count = i.second;
        }
    }
    return res; 

}
int main () {   
  const int N = 1000;
  array<long, N> array; 
  
  for(size_t i = 0; i < N; ++i)
  {
      array[i] = rand() % N;
  }
  long result = mostFreuency(array);

  cout << result << endl;
    
return 0;   
}   