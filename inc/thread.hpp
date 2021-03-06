#ifndef PARA_ALGO_HPP
#define PARA_ALGO_HPP

#include <pthread.h>
namespace mt{

class Thread {
public:
    Thread(const pthread_attr_t * attr, void* (*func)(void *), void* arg); 
    ~Thread();
    void detach();
    static pthread_t self(Thread thread);
    static void join(pthread_t);
    void join();
    pthread_t self();
    void* result();

private:
    Thread(Thread const& a_src);
    pthread_t m_tid;
    void* m_result;
    bool m_wasJoined;
};

} //namespace mt

#include "./inl/thread.hxx"

#endif//PARA_ALGO_HPP