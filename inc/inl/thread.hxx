#ifndef THREAD_HXX
#define THREAD_HXX

#include <iostream>
#include <algorithm>
#include <cassert>
#include <pthread.h>

namespace mt
{

Thread::Thread(const pthread_attr_t * attr, void* (*func)(void *), void* arg) 
: m_tid(pthread_self())
, m_wasJoined(false)
{
    pthread_t thread;
    pthread_create(&thread, attr, func, arg);       
}
   
Thread::~Thread()
{
    //if(!wasJoined)   join(tid, 0);
    assert(m_wasJoined);
}

void detach()
{
    pthread_detach(pthread_self());
}

pthread_t Thread::self()
{
    return pthread_self();
}

inline static pthread_t self(Thread thread)
{
    return thread.self();
}

inline static void join(pthread_t a_tid)
{
    pthread_join(a_tid, 0);
}
    
void Thread::join()
{
    pthread_join(m_tid, 0);
    m_wasJoined = true;
}



} // namespace mt

#endif//THREAD_HXX