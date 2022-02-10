#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

namespace Cpp {

template <typename T>
inline Queue<T>::Queue(size_t a_value)
:m_capacity(a_value)
,m_arr(new T[m_capacity])
,m_size(0)
,m_head(0)
,m_tail(0)
{
  
}
template <typename T>
Queue<T>::Queue(Queue const& a_source)
: m_capacity(a_source.m_capacity)
, m_arr(new T[a_source.m_capacity])
, m_size(a_source.m_size)
,m_head(a_source.m_head)
,m_tail(a_source.m_tail)
{
 for(size_t i = 0; i < m_capacity; i++)
 {
        m_arr[i] = a_source.m_arr[i];
 }
}
template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const& a_source)
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
Queue<T>::~Queue()
{
	delete[] m_arr;
}
template <typename T>
 void Queue<T>::enqueue(T const& a_data)
 {
      assert(!isFull());
     m_arr[m_head] = a_data;
     m_head = (m_head +1)%m_capacity;
     m_size++;
 }
 template <typename T>
 T Queue<T>::dequeue()
 {
    assert(!isEmpty());
   T item  = m_arr[m_tail];
   m_tail = (m_tail +1)%m_capacity;
     m_size--;
     return item;
 }

template <typename T>
bool Queue<T>::isEmpty() const
{
  return m_size == 0;
}
template <typename T>
bool Queue<T>::isFull() const
{
  return m_size == m_capacity;
}
template <typename T>
size_t Queue<T>::size() const
 {
     return m_size;
 }
 template <typename T>
 void Queue<T>::clear()
 {
     m_size = 0;
     m_head = 0;
     m_tail = 0;
 }
}