#include <iostream>
#include <stddef.h>
#include <list>
#include <stack>
using namespace std;

list<int> reverseList(list<int>& a_list)
{
    stack<int> myStack;
    for (auto it = a_list.begin(); it != a_list.end(); it++)
    {
        myStack.push(*it);
        
    }
    list<int> second;
    size_t size = myStack.size();
    for (auto i = 0; i < size; ++i)
    {
        second.push_back(myStack.top());
        myStack.pop();
    }
    return second;
}

int main () 
{
    list<int> first = {1,2,3,4,5,6,7,8};
    list<int> res = reverseList(first);
    for (auto it = res.begin(); it != res.end(); it++)
    {
       cout << *it << " ";
    }
   
   cout << endl;
    return 0;
}