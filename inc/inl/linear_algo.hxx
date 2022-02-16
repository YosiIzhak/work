#ifndef LINEAR_ALGO_HXX
#define LINEAR_ALGO_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "utils.hpp"



namespace cpp
{

template <typename T>
void createChaos(std::vector<T> &a_vector, size_t a_size)
{
    for(size_t i = 0; i < a_size; i++)
    {
        T number =  random();
        a_vector.push_back(number);
    }
}

template <typename T>
double sum(std::vector<T> &a_vector, size_t a_size)
{
    double sum;
    for (size_t i = 0; i < a_size; i++)
    {
          sum += a_vector[i]; 
    }
   return sum;
}

template <typename T>
void oddOut(std::vector<T> &a_vector, size_t a_size)
{
    for (size_t i = 0; i < a_vector.size(); i++)
    {
         if(a_vector[i] % 2 != 0)
         {
             a_vector.erase(a_vector.begin()+i);
             i--;
         } 
    }
}

template <typename T>
void extremes(std::vector<T> &a_vector, int& a_min, int& a_max)
{
     a_min = a_vector[0], a_max = a_vector[0];
    for (size_t i = 1; i < a_vector.size(); i++)
    {
         if(a_vector[i] > a_max)
         {
            a_max = a_vector[i];
         }
         if(a_vector[i] < a_min)
         {
            a_min = a_vector[i];
         }  
    }
    
}

template <typename T>
//requires: value's range in array size
int firstDuplicate(std::vector<T> a_vector)
{
    for (size_t i = 0; i < a_vector.size(); i++)
    {
        if (a_vector[abs(a_vector[i]) - 1] < 0)
            return abs(a_vector[i]);
        else
            a_vector[abs(a_vector[i]) - 1] = -a_vector[abs(a_vector[i]) - 1];
    }
    return -1;
}  




} //cpp namespace

#endif // QUICK_SORT_HXX

