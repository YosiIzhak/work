#include <iostream>    
#include <algorithm> 

using namespace std;
int* myRotate(int* array1, int size1, int num)
{
    int temp[num];
    for (int i=0; i < num; ++i)
    {
        temp[i]= array1[i];
    }
    int x=0;
    for(int j = num;j< size1; j++)
    {
        array1[x]=array1[j];
        x++;
    }
    x=0;
    for (int k=size1- num; k < size1; k++)
    {
        array1[k]=temp[x];
        x++;
    }
    return array1;
}

int main () 
{
    int firstArray[] = {1,2,4,6,7,8,9};
   
    int* ans = myRotate(firstArray,7, 3);
    for (int i = 0; i < 7; ++i)
    {
          cout << ans[i] << " ";
    }
    return 0;
}