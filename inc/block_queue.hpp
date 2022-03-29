#ifndef BLOCK_QUEUE_HPP
#define BLOCK_QUEUE_HPP

//#include <cstddef> 
#include <pthread.h> 
#include "mutex.hpp"
#include "queue.hpp"
namespace mt {

template <typename T>
class BlockQueue
{
public:
    explicit BlockQueue(size_t a_size = 64);
    
    ~BlockQueue();
    bool enqueue(T const& item);
    void dequeue(bool& ok, T& a_res);
    T getHead();
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    void clear();
   
private:
    BlockQueue(BlockQueue const& a_source); //no impl by design
    BlockQueue& operator=(BlockQueue const& a_source);
    bool nonLockEmpty() const;
    bool nonLockFull() const;

private:
   cpp::Queue<T> m_queue;
   mutable mt::Mutex m_mutex;
};
}//namespace
#include "./inl/block_queue.hxx"

#endif //BLOCK_QUEUE_HPP


