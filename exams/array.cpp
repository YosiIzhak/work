#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include "array.hpp"

Array::Array(size_t a_size)
:m_capacity(a_size)
,m_size(0)
{
   m_arr = new int[a_size];
}
Array::Array(Array const& a_source)
: m_capacity(a_source.m_capacity)
, m_arr(new int[a_source.m_capacity])
, m_size(a_source.m_size)
{
    memcpy(m_arr, a_source.m_arr, sizeof(a_source.m_arr[0]) * a_source.m_size);
}
Array::~Array()
{
	delete[] m_arr;
}
Array& Array::operator=(Array const& a_source)
{
    m_capacity = a_source.m_capacity;
    m_size = a_source.m_size;
    delete[] m_arr;
    m_arr = new int[a_source.m_capacity];
    memcpy(m_arr, a_source.m_arr, sizeof(a_source.m_arr[0]) * a_source.m_size);
    return *this;
}
inline bool Array::isEmpty() const
{
  return m_size == 0;
}
inline bool Array::isExist(int const& data) const
{
  for(size_t i = 0; i < m_size; i++)
  {
      if (m_arr[i] == data)
      {
          return true;
      }
  }
  return false;
}
 inline size_t Array::arraySize() const
 {
     return m_size;
 }
 void Array::add(int const& data)
 {
     m_arr[m_size] = data;
     m_size++;
 }
 void Array::remove(int const& index)
 {
    if (index > m_size)
    {
        return;
    }
    for (size_t i = index; i < m_size; i++)
    {
        m_arr[i] = m_arr[i+1];
        m_size--;
    }