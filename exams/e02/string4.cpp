#include <string>
#include <ostream> 
#include <iostream>

using namespace std;
 

bool stringRotate(string str1, string str2)
{
   
   if (str1.length() != str2.length())
   {
        return false;
   }
       
 
   string temp = str1 + str1;
  return (temp.find(str2) != string::npos);
}
 

int main()
{
   string str1 = "AACDE", str2 = "ACDEA";
   if (stringRotate(str1, str2))
     cout << ("Strings are rotations of each other");
   else
    cout <<("Strings are not rotations of each other");
   return 0;
}