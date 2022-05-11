#include <iostream>
#include <stddef.h>
#include <list>
#include <stack>
using namespace std;

list<int> revmoveFromList(list<int>& a_list, size_t a_num)
{
    auto ptr = a_list.begin();
    auto sec_ptr = a_list.begin();
    for(size_t i = 0; i < a_num; ++i)
    {
        ptr++;
    }
    while (ptr != a_list.end())
    {
        ptr++;
        sec_ptr++;
    }
    sec_ptr = a_list.erase(sec_ptr);
    return a_list;
}

int main () 
{
    list<int> first = {1,2,3,4,5,6,7,8};
    list<int> res = revmoveFromList(first, 3);
    for (auto it = res.begin(); it != res.end(); it++)
    {
       cout << *it << " ";
    }
   
   cout << endl;
    return 0;
}