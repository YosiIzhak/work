#include <iostream>    
#include <algorithm> 
#include <array>
#include <string>

using namespace std;

array<int, 10> sortArray(array<int, 10>& a_input)
{
   int counter0 = 0, counter1 = 0, counter2 = 0;
   
    for (auto it = begin(a_input); it!= end(a_input); ++it)
    {
        if(*it == 0)
            counter0++;
        if(*it == 1)
            counter1++;
        if(*it == 2)
            counter2++;  
    }
    fill_n (a_input.begin(),counter0,0);    
    fill_n (a_input.begin()+counter0, counter1, 1);
    fill_n (a_input.begin()+counter0+counter1, counter2, 2);   
   return a_input;
}

int main () 
{
   array<int, 10> input = {1,2,1,0,0,0,2,2,1,0};
   array<int, 10> res = sortArray(input);
    for (int j = 0; j < res.size(); j++)
   {
        cout << res[j] << " ";
   }
   cout << endl;
    return 0;
}