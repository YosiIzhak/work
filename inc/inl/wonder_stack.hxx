#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

namespace Cpp {

template <typename T>
WonderStack<T>::WonderStack(size_t a_value)
: m_capacity(a_value)
, m_size(0)
, m_in<T>(a_value)
, m_out<T>(a_value)
{
}

template <typename T>
 void WonderStack<T>::push(T const& a_data)
 {
    assert(!isFull());
    m_in.enqueue(a_data);
     m_size++;
 }
 template <typename T>
 T WonderStack<T>::pop()
 {
    assert(!isEmpty());
   while(m_in.size() > 1)
   {
     m_out.enqueue(m_in.dequeue());
   }
   T item = m_in.dequeue();
   m_size--;
   while(m_in.size() < m_size)
   {
     m_in.enqueue(m_out.dequeue());
   }
   
   return item;
 }

template <typename T>
T WonderStack<T>::top() const
{
  return m_in.getHead();
}

template <typename T>
bool WonderStack<T>::isEmpty() const
{
  return m_in.size() == 0;
}
template <typename T>
bool WonderStack<T>::isFull() const
{
  return m_in.size() == m_capacity;
}
template <typename T>
size_t WonderStack<T>::size() const
 {
     return m_size;
 }
 template <typename T>
 void WonderStack<T>::clear()
 {
    for (size_t i = 0; i < m_size; i++)
    {
      T item = pop();
    }
    m_size = 0;
 }
}