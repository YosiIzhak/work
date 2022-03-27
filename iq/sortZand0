#include <iostream>
#include <algorithm>
#include <stddef.h>

using namespace std;
void sortArray(int* array1, int size1)
{
    int count[3] = {0};
    for_each(array1,array1+size1, [&count](int e)
    {
        ++count[e+1];
    });
    //cout << count[0] << "\n";
    //cout << count[1] << "\n";
    //cout << count[2] << "\n";
    size_t i;
    for(i=0 ; i < count[0]; ++i)
    {
       array1[i] = -1;
    }
    for( ; i < count[1]+count[0]; ++i)
    {
       array1[i] = 0;
    }
    for( ; i < count[2]+count[0]+count[1]; ++i)
    {
       array1[i] = 1;
    }
    return;
}

int main () 
{
    int firstArray[] = {1,0,1,1,0,0,-1,-1};
   
    sortArray(firstArray,8);
    for (int i = 0; i < 8; ++i)
    {
          cout << firstArray[i] << " ";
    }
    return 0;
}