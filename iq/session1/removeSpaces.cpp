#include<iostream>   
#include<algorithm>   
#include<array>  
#include <stdlib.h> 
#include <cmath>

using namespace std;   

void removeSpaces(string& str)
{
   bool space = false;
   int it = 0;

   while (str[it])
   {
    char c = str[it];
    if (isspace(c) && space) 
    {
        str.erase(str.begin() + it);
        it--; 
    }
    else if (isspace(c))
    {
        space = true;
    }
    else
    {
        space = false;
    }
    it++;
   }
}

int main () {   
   string str ("Example  sentence  to test          remove   yes!!");
   cout << str << endl;
   removeSpaces(str);
    
   cout << str << endl;
      
return 0;   
}   