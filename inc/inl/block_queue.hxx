#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

//#include <numeric>

namespace mt {

template <typename T>
BlockQueue<T>::BlockQueue(size_t a_value)
{
    m_queue = cpp::Queue<T>(a_value);
    m_mutex = mt::Mutex();
}

template <typename T>
BlockQueue<T>::~BlockQueue()
{
    //m_queue.~Queue();
}

template <typename T>
 bool BlockQueue<T>::enqueue(T const& a_data)
 {
      m_mutex.lock();
    if(nonLockFull())
    {
        m_mutex.unlock();
        return false;
    }
    m_queue.enqueue(a_data);
    m_mutex.unlock();
    return true;
 }

template <typename T>
T BlockQueue<T>::dequeue(T* data, bool* ok)
 {
     m_mutex.lock();
   if(nonLockEmpty())
   {
       m_mutex.unlock();
       return false;
   }
    T res = m_queue.dequeue();
    m_mutex.unlock();
    return res;
 }

template <typename T>
T BlockQueue<T>::getHead()
{
    m_mutex.lock();
    T res = m_queue.getHead();
    m_mutex.unlock();
    return res;
}

template <typename T>
bool BlockQueue<T>::isEmpty() const
{
   m_mutex.lock();
   bool res =  m_queue.isEmpty();
   m_mutex.unlock();
    return res;
}

template <typename T>
bool BlockQueue<T>::nonLockEmpty() const
{
    bool res =  m_queue.isEmpty();
    return res;
}

template <typename T>
bool BlockQueue<T>::isFull() const
{
   m_mutex.lock();
   bool res = m_queue.isFull();
   m_mutex.unlock();
   return res;
}

template <typename T>
bool BlockQueue<T>::nonLockFull() const
{
    bool res = m_queue.isFull();
    return res;
}

template <typename T>
size_t BlockQueue<T>::size() const
 {
    m_mutex.lock(); 
    size_t res =  m_queue.size();
    m_mutex.unlock();
    return res;
 }

template <typename T>
void BlockQueue<T>::clear()
 {
    m_mutex.lock(); 
     m_queue.clear();
    m_mutex.unlock();
 }


} //namespace