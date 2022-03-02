#ifndef MUTEX_HXX
#define MUTEX_HXX

#include <iostream>
#include <algorithm>

namespace mt{

Mutex::Mutex()
{
    pthread_mutex_init(&m_mutex, 0);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&m_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&m_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&m_mutex);
}


} //namespace mt
#endif//MUTEX_HXX