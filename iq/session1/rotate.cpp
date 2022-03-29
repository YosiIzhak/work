#include<iostream>   
#include<algorithm>   
#include<vector>   
using namespace std;   
  
void myRotate(vector<int>& array1, int num)
{
   if(num >= 0)
   {
      int rotL = num;
      rotate(array1.begin(), array1.begin()+rotL, array1.end());  
       
   }
   else
   {
       int rotR = num * -1; 
       rotate(array1.begin(), array1.begin()+array1.size()-rotR, array1.end());
       
   }
     
}
int main () {   
    vector<int> vec1{1,2,3,4,5,6,7,8,9};   
    myRotate(vec1, -2);
     cout << "New vector after left rotation :";   
    for (int i=0; i < vec1.size(); i++)   
        cout<<" "<<vec1[i];   
    cout << "\n\n";  
    
    
return 0;   
}