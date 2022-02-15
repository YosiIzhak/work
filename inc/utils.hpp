#ifndef UTILS_H
#define UTILS_H
#include <cstddef>

#define arraySize(T) sizeof(T)/sizeof(T[0])

template <typename T>
struct NaturalLess
{
    bool operator()(T const& a_first, T const& a_second) const
    {
        return a_first < a_second;
    }
};

void reverseIntArr(int* a_arr, size_t a_arrSize);

void swapInt(int* a_first, int* a_second);

int minInt (int _a , int _b);

void arrCopy(int* a_first, int* a_second, size_t n);

int* randomIntArray(size_t n);


#endif /*#ifndefUTILS_H*/