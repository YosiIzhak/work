#ifndef MUTEX_HPP
#define MUTEX_HPP

namespace mt{

class Mutex{

public:

    Mutex();

    ~Mutex();

    void lock();

    void unlock();

private:

    pthread_mutex_t m_mutex;

};

}// namespace mt

#include "./inl/mutex.hxx"

#endif//MUTEX_HPP