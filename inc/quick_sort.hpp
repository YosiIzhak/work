#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include <cstdlib> //size_t
#include "ball.hpp"
namespace cpp
{



template <typename T>
inline void quickSort(T* a_array, size_t a_length);


}//end of namespace

#include "./inl/quick_sort.hxx"

#endif