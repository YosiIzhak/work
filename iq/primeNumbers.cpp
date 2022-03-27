#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
vector<int> largerRight(int num)
{
    vector<int> result;
 
    
    stack<int> s;
 
    
    for (int i = n - 1; i >= 0; i--)
    {
       
        while (!s.empty())
        {
           
            if (s.top() <= input[i]) {
                s.pop();
            }
           
            else {
                result[i] = s.top();
                break;
            }
        }
 
       
        s.push(input[i]);
    }
 
    return result;
}
 
int main()
{
    vector<int> input = { 2, 7, 3, 5, 4, 6, 8 };
 
    vector<int> result = largerRight(input);
    for (int i: result) {
        cout << i << ' ';
    }
 
    return 0;
}