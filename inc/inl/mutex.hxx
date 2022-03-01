#ifndef MUTEX_HXX
#define MUTEX_HXX

#include <iostream>
#include <algorithm>

namespace mt{

Mutex::Mutex()
{
    pthread_mutex_init(&mtx, 0);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&mtx);
}

void Mutex::lock()
{
    pthread_mutex_lock(&mtx);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&mtx);
}


} //namespace mt
#endif//MUTEX_HXX