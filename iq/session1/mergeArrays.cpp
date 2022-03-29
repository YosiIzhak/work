#include <iostream>    
#include <algorithm> 

using namespace std;
int* myMerge(int* array1, int size1, int* array2, int size2)
{
    int j = 0;
    for(int i = size2-1; i >= 0; --i)
    {
        if (array2[i] > array1[j])
        {
            array1[j] = array2[i];
            ++j;
        }
        else
        {
            break;
        }
        
    }
    sort(array1, array1 + size1);
    return array1;
}

int main () 
{
    int firstArray[] = {1,2,4,6,7,8};
    int secondArray[] = {3,5,9};
    myMerge(firstArray,6, secondArray,3);
    for (int i = 0; i < 6; ++i)
    {
          cout << firstArray[i] << " ";
    }
    return 0;
}
