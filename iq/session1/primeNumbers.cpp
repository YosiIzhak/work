#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
 
bool isPrime(int a_num)
{
    for(size_t i = 2; i <= sqrt(a_num); ++i)
    {
        if (a_num % i == 0)
        {
            return false;
        }
    }
    return true;
}
void primeNumbers(int amount)
{
    vector<int> result;
    int count = 0, x = 3;
    while (count < amount)
    {
       bool res = isPrime(x);
       if(res)
        {
           count++;
           result.push_back(x);
        }
        x++;
    }
    for (int i: result) 
    {
        cout << i << ' ';
    }
    cout << endl;
}

int main()
{
    primeNumbers(10);
    return 0;
}