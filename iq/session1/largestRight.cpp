#include <iostream>    
#include <algorithm> 

using namespace std;
void largestRight(int* array1, int size1)
{
    int max = array1[size1-1];
    int temp = max;
    for (int i = size1 - 1; i >= 0; --i)
    {
        if (array1[i] > max)
        {
            temp = array1[i];
        }
        array1[i] = max;
       
        max = temp;
    }
    return;
}

int main () 
{
    int firstArray[] = {5,2,0,7,9,0,2,7};
   
    largestRight(firstArray,8);
    for (int i = 0; i < 8; ++i)
    {
          cout << firstArray[i] << " ";
    }
    return 0;
}