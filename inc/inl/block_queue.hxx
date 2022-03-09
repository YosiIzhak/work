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
    try
    { 
        m_mutex = mt::Mutex();
    }
    catch(cpp::MutexExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n";
        throw;
    }
}

template <typename T>
BlockQueue<T>::~BlockQueue()
{
    //m_queue.~Queue();
}

template <typename T>
 bool BlockQueue<T>::enqueue(T const& a_data)
 {
    try
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
    catch(cpp::MutexExceptions const& a_exception)
    {
        std::clog << a_exception.getFunctionName() << " fail! error number: " << a_exception.getErrorNumber() << "\n";
        throw; 
    }
 }

template <typename T>
T BlockQueue<T>::dequeue(bool& ok)
 {
     m_mutex.lock();
    
   if(nonLockEmpty())
   {
       ok = false;
       m_mutex.unlock();
       return 0;
   }
    T res = m_queue.dequeue();
    ok = true;
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