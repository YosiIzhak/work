//Leet code 62
#include <iostream>    
#include <algorithm> 
#include <vector>
#include <cstring>

using namespace std;
 int* uniquePaths(int a_heigth, int a_width)
 {
   int* matrix = new int[a_heigth * a_width];
   memset( matrix, 0, sizeof(matrix));

    for(int i = a_width-1; i < a_heigth*a_width; i=i+a_width)
    {
        matrix[i] = 1;
    }
   
    for(int j = (a_heigth-1) * a_width; j < a_heigth * a_width; ++j)
    {
        matrix[j] = 1;
    }
    for(int i = a_heigth-2; i >= 0; --i)
    {
        for(int j = a_width-2; j >=0; --j)
        {
            matrix[i*a_width+j] = matrix[i*a_width+j+1] + matrix[(i+1)*a_width+j];
        }
    }
    for(int i = 0; i < a_heigth; i++)
    {
        for(int j = 0; j < a_width; ++j)
        {
            cout << matrix[i*a_width+j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    return matrix;
}

int main () 
{
    
   
    int* res = uniquePaths(3,7);
    cout << res[0] << endl;
    delete [] res;
    return 0;
}