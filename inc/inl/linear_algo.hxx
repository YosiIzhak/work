#ifndef LINEAR_ALGO_HXX
#define LINEAR_ALGO_HXX

#include <cassert>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "utils.hpp"
#include <map>
#include <set>

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
template <typename T>
struct NaturalLess
{
    bool operator()(T const& a_first, T const& a_second) const
    {
        return a_first < a_second;
    }
};

template <typename T>
struct NaturalGreterThan
{
    bool operator()(T const& a_first, T const& a_second) const
    {
        return a_first > a_second;
    }
};

template<typename T, typename Comparator>
static size_t findx(std::vector<T> const& a_vector, Comparator a_compar)
{
    size_t const size = a_vector.size();
    size_t index = 0;

    for(size_t i = 0; i < size; ++i)
    {
        if(a_compar(a_vector[i], a_vector[index]))
        {
            index = i;
        }
    }
    return index;
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

    minMax.first = findx(a_vector, NaturalLess<T>());
    minMax.second = findx(a_vector, NaturalGreterThan<T>());
    return minMax;
}
    template<typename T>
    void setMin(size_t index, std::vector<T> const& a_vec, std::pair<size_t, size_t>& minMax)
    {
        if( minMax.first > std::min(a_vec[index], a_vec[index+1]))
        {
            minMax.first = std::min(a_vec[index], a_vec[index+1]);
        }
    }
    template<typename T>
    void setMax(size_t index, std::vector<T> const& a_vec, std::pair<size_t, size_t>& minMax)
    {
        if( minMax.second < std::max(a_vec[index], a_vec[index+1]))
        {
            minMax.second = std::max(a_vec[index], a_vec[index+1]);
        }
    }

template<typename T>
std::pair<size_t, size_t> extremes2(std::vector<T> const& a_vector)
{
    size_t j = 0;
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
       j = 2;
    }

    else
    {
        minMax.first = minMax.second = a_vector[0];
        j = 1;
    }
    
    for( size_t i = j; i < a_vector.size(); i = i+2)
    {
        setMin(i,a_vector, minMax);
        setMax(i,a_vector, minMax);
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

namespace details_impl
{
template<typename T>
struct EqualByPointer
{
    bool operator()(const T* a_first, const T* a_second) const
    {
        return *a_first < *a_second;
    }
};
} // end if details_impl

template <typename T>
size_t countCommontStrange2(std::vector<T> const& a_first, std::vector<T> const& a_second, std::vector<T> const& a_third)
{
    using namespace std;
    using namespace details_impl;
    size_t count = 0;
    size_t size = a_first.size();
    set<T const*, EqualByPointer<T> > set;

    for(size_t i = 0; i < size; i++)
    {
        set.insert(&a_first[i]);
    }
    
    size = a_third.size();
    for(size_t i = 0; i < size; i++)
    {
        set.erase(&a_third[i]);
    }

    size = a_second.size();
    for(size_t i = 0; i < size; i++)
    {
        count += set.count(&a_second[i]);
    }

    return count;
}
} //cpp namespace

#endif // QUICK_SORT_HXX




