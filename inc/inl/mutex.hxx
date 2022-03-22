

#ifndef MUTEX_HXX

#define MUTEX_HXX


#include <cassert>

#include "mutex_exception.hpp"


namespace mt

{

inline Mutex::Mutex()

{

   int r = pthread_mutex_init(&m_mutex,0);

   assert(r == 0);

}


inline Mutex::~Mutex()

{

   pthread_mutex_destroy(&m_mutex); 

}


inline void Mutex::lock()

{

   pthread_mutex_lock(&m_mutex);

}


inline void Mutex::unlock()

{

   pthread_mutex_unlock(&m_mutex);

}



LockGuard::LockGuard(mt::Mutex& a_mutex)

: m_mutex(a_mutex)

{

   m_mutex.lock();

}


LockGuard::~LockGuard()

{

   m_mutex.unlock();

}



}//namespace mt


#endif//MUTEX_HXX

