#include <iostream>    
#include <algorithm> 
#include <vector>
#include <string>

using namespace std;

void reverseString(string& a_input)
{
    string res="", temp ="";
     int i = 0;
     while (i <= a_input.size())
     {
         if(a_input[i] != ' ')
         {
            temp.push_back(a_input[i]);
         }
         else
         {
            reverse(temp.begin(), temp.end());
            res.append(temp);
            res.push_back(' ');
            temp.clear();
         }
         ++i;
     }
     reverse(temp.begin(), temp.end());
     res.append(temp);
     res.push_back(' ');
     temp.clear();
    reverse(res.begin(), res.end());
  cout << res <<endl;
}

int main () 
{
   string a = "abc def ghi";
   reverseString(a);
    return 0;
}