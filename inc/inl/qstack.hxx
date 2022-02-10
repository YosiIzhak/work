#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

namespace Cppp {

template <typename T>
Qstack<T>::Qstack(size_t a_value)
:m_capacity(a_value)
,m_size(0)
,m_in<T>(a_value)
,m_out<T>(a_value)
{
  
}
template <typename T>
Qstack<T>::Qstack(Qstack const& a_source)
: m_capacity(a_source.m_capacity)
, m_size(a_source.m_size)

{
 for(size_t i = 0; i < m_capacity; i++)
 {
        m_arr[i] = a_source.m_arr[i];
 }
}
template <typename T>
Qstack<T>& Qstack<T>::operator=(Qstack<T> const& a_source)
{
    m_capacity = a_source.m_capacity;
    m_size = a_source.m_size;
    T* arr = new T[m_capacity];
    m_head = a_source.m_head;
    m_tail = a_source.m_tail;
    for(size_t i = 0; i < m_capacity; i++)
    {
        arr[i] = a_source.m_arr[i];
    }
    delete[] m_arr;
    m_arr = arr;
    return *this;
}
template <typename T>
Qstack<T>::~Qstack()
{
	delete[] m_arr;
}
template <typename T>
 void Qstack<T>::enqueue(T const& a_data)
 {
      assert(!isFull());
     m_arr[m_head] = a_data;
     m_head = (m_head +1)%m_capacity;
     m_size++;
 }
 template <typename T>
 T Qstack<T>::dequeue()
 {
    assert(!isEmpty());
   T item  = m_arr[m_tail];
   m_tail = (m_tail +1)%m_capacity;
     m_size--;
     return item;
 }

template <typename T>
bool Qstack<T>::isEmpty() const
{
  return m_size == 0;
}
template <typename T>
bool Qstack<T>::isFull() const
{
  return m_size == m_capacity;
}
template <typename T>
size_t Qstack<T>::size() const
 {
     return m_size;
 }
 template <typename T>
 void Qstack<T>::clear()
 {
     m_size = 0;
 }
}