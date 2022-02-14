#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP
#include <cstdlib> //size_t
#include "ball.hpp"
namespace cpp
{

typedef enum ErrQuick
{
    QUICK_OK,
    QUICK_NOT_INITIALIZED,
    QUICK_SIZE_TOO_SMALL

}ErrQuick;

template <typename T>
ErrQuick quickSort (T* a_array, size_t a_size);
template <typename T>
void quickPrint(T* a_array, size_t a_size);
template <typename T>
void charPrint(T* a_array,size_t a_size);
template <typename T>
bool operator<(const Ball &x, const Ball &y);
template <typename T>
bool operator<=(const Ball &x, const Ball &y);
template <typename T>
bool operator>(const Ball &x, const Ball &y);
}//end of namespace

#include "./inl/quick_sort.hxx"

#endif