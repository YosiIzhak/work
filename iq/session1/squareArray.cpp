#include<iostream>   
#include<algorithm>   
#include<vector>  
#include <stdlib.h> 
#include <cmath>

using namespace std;   

void squareArray(vector<int>& a_numbers)
{
    auto begin = a_numbers.begin();
    auto end = a_numbers.end();
    auto isPositive = [](int a_num){return a_num >= 0;};
    auto pivot = std::find_if(begin, end, isPositive);
    auto pow2 = [](int& a_num){a_num =  a_num*a_num;};
 
    if(pivot == begin)
    {
        for_each(begin, end, pow2);
        return;
    }
    reverse(begin, pivot);
    for_each(begin, end, pow2);
    inplace_merge(begin, pivot, end);
}
 
int main()
{
    vector<int> vec = { -6, -3, -1, 2, 4, 5 };
    int n = vec.size();
 
    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
        
    squareArray(vec);
 
    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
    {
         cout << vec[i] << " ";
    }
       cout << endl;
 
    return 0;
}
///

