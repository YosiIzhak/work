#ifndef LINEAR_ALGO_HXX
#define LINEAR_ALGO_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "utils.hpp"
#include <map>


namespace cpp
{

template<typename T>
void createChaos(std::vector<T>& a_vector, size_t a_size, size_t a_max)
{
    a_vector.reserve(a_size);
    T random;
    for(size_t i = 0; i < a_size; i++)
    {
        random = T(rand())/T(RAND_MAX) + rand()%a_max;
        a_vector.push_back(random);
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
void oddsOut(std::vector<T> &a_vector, size_t a_size)
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

template<typename T>
static size_t findx(std::vector<T> const& a_vector, int a_type)
{
    size_t const size = a_vector.size();
    size_t index = 0;
    size_t value = a_vector[0];

    if(a_type == 0)
    {
        for(size_t i = 0; i < size; i++)
        {
            if(a_vector[i] < a_vector[index])
            {
                index = i;
                value = a_vector[i];
            }
        }
    }
    if(a_type == 1)
    {
        for(size_t i = 0; i < size; i++)
        {
            if((a_vector[i] > a_vector[index]))
            {
                index = i;
                value = a_vector[i];
            }
        }
    }
    return value;
}

template<typename T>
std::pair<size_t, size_t> extremes(std::vector<T> const& a_vector)
{
    std::pair<size_t, size_t> minMax;

    if(a_vector.size() == 0)
    {
        minMax.first = a_vector.size();
        minMax.second = a_vector.size();
        return minMax;
    }

    minMax.first = findx(a_vector, 0);
    minMax.second = findx(a_vector, 1);
    return minMax;
}

template<typename T>
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector)
{
    std::pair<size_t, size_t> minMax;
    if(a_vector.size() == 0)
    {
        minMax.first = a_vector.size();
        minMax.second = a_vector.size();
        return minMax;
    }
    else if(a_vector.size() % 2 == 0)
    {
        minMax.first = std::min(a_vector[0], a_vector[1]);
        minMax.second = std::max(a_vector[0], a_vector[1]);
    }
    else
    {
        minMax.first = minMax.second = a_vector[0];
    }
    for(size_t i = 2; i < a_vector.size(); i = i+2)
    {
        if( minMax.first > std::min(a_vector[i], a_vector[i+1]))
        {
            minMax.first = std::min(a_vector[i], a_vector[i+1]);
        }
        if( minMax.second < std::max(a_vector[i], a_vector[i+1]))
        {
            minMax.second = std::max(a_vector[i], a_vector[i+1]);
        }
    }
    return minMax;
}

template<typename T>
size_t firstDuplicate(std::vector<T> const& a_vector) 
{
    using std::map;
    map<T, size_t> mapT;
    size_t size = a_vector.size();
    size_t duplicate = a_vector.size();

     for(size_t i = 0; i < size; i++)
    {
        T element = a_vector[i];
        if(mapT[element] == 0)
        {
            mapT[element] = i;
        }
        else
        {
            if(i < duplicate)
            {
                duplicate = mapT[element];
            }
        }
    }
    return duplicate;
}

template<typename T>
size_t countCommontStrange(std::vector<T> &a_first, std::vector<T> &a_second, std::vector<T> &a_third)
{
    size_t count = 0;
    for (std::vector<int>::iterator it = a_first.begin() ; it != a_first.end(); ++it)
    {
        if  ((std::find(a_second.begin(), a_second.end(), *it) != a_second.end()) &&
        !(std::find(a_third.begin(), a_third.end(), *it) != a_third.end())) 
        {
            count++;
        }
    }
    
    return count;
}

} //cpp namespace

#endif // QUICK_SORT_HXX


// template <typename T>
// //requires: value's range in array size
// int firstDuplicate(std::vector<T> a_vector)
// {
//     for (size_t i = 0; i < a_vector.size(); i++)
//     {
//         if (a_vector[abs(a_vector[i]) - 1] < 0)
//             return abs(a_vector[i]);
//         else
//             a_vector[abs(a_vector[i]) - 1] = -a_vector[abs(a_vector[i]) - 1];
//     }
//     return -1;
// }  

