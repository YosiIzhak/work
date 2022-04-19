#include <iostream>    
#include <algorithm> 
#include <array>
#include <string>

using namespace std;

string removeSpaces(string& a_input)
{
   for(auto it = a_input.begin(); it != a_input.end(); ++it)
   {
       if(*(it) == ' ' && *(it + 1) == ' ')
       {
           a_input.erase(it + 1);
           --it;
       }
   }
      
   return a_input;
}

int main () 
{
   string input = {"a bb   cc    ddddde                 !!!!!!1"};
   string res = removeSpaces(input);
    cout << res << endl;
    return 0;
}