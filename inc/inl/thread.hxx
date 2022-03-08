#ifndef THREAD_HXX
#define THREAD_HXX

#include <cassert>
#include <iostream>
#include "pthread.h"


namespace mt
{


Thread::Thread(const pthread_attr_t * attr, void* (*func)(void *), void* arg) 
: m_tid(pthread_self())
, m_result(0)
, m_wasJoined(false)
{
    pthread_create(&m_tid, attr, func, arg);       
}

inline Thread::Thread(Thread const& a_src)
: m_tid(a_src.m_tid)
, m_result(a_src.m_result)
, m_wasJoined(a_src.m_wasJoined)
{
    Thread &t = const_cast<Thread &>(a_src);
    t.m_wasJoined = false;
    t.m_tid = 0;
}

inline Thread::~Thread() 
{
    assert(m_wasJoined);
}

inline void Thread::join()
{
    int r = pthread_join(m_tid, &m_result);
    if (r != 0)
    {
        std::cout << "Error: pthread_create fail\n";
        exit(EXIT_FAILURE);
    }
    m_wasJoined = true;
}

inline pthread_t Thread::self(Thread thread)
{
    return thread.self();
}

inline void Thread::join(pthread_t a_tid)
{
    pthread_join(a_tid, 0);
}

void detach()
{
    pthread_detach(pthread_self()); 
}

inline void* Thread::result()
{
    return m_result;
}


} // namespace mt

#endif //THREAD_HXX