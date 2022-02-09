#ifndef ARRAY_H
#define ARRAY_H
#include <cstdlib> 

class Array
{
public:
    Array(size_t a_size);
    Array(Array const& a_source);
    Array& operator=(Array const& a_source);
    ~Array();
    inline size_t arraySize() const;
    inline bool isEmpty() const;
    void add(int const& data);
    inline bool isExist(int const& data) const;

private:
    size_t m_capacity;
    int* m_arr;
    size_t m_size;

};

#endif