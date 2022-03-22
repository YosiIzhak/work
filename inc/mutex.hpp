

#ifndef MUTEX_HPP

#define MUTEX_HPP


#include <pthread.h>


namespace mt

{


class Mutex

{

public:

    Mutex();

    ~Mutex();


    void lock();

    void unlock();


private:

    Mutex(Mutex const &a_source);

    Mutex& operator=(Mutex const& a_source);


private:

    pthread_mutex_t m_mutex;

};

struct LockGuard

{

    LockGuard(mt::Mutex& a_mutex);

    ~LockGuard();

private:

    LockGuard(LockGuard const& a_source);

    LockGuard& operator=(LockGuard const& a_source);

    //void* operator new(std::size_t a_size) throw (std::bad_alloc);

    

private: 

    Mutex& m_mutex;

};


}//namespace mt


#include "./inl/mutex.hxx"


#endif//MUTEX_HPP

