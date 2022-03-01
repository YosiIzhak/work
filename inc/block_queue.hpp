#ifndef BLOCK_QUEUE_HPP
#define BLOCK_QUEUE_HPP

//#include <cstddef> 
#include <pthread.h>

namespace cpp {

template <typename T>
class BlockQueue
{
public:
    BlockQueue(size_t a_size = 64);
    BlockQueue(BlockQueue const& a_source);
    BlockQueue& operator=(BlockQueue const& a_source);
    ~BlockQueue();
    void enqueue(T const& item);
    T dequeue();
    T getHead();
    bool isEmpty() const;
    bool isFull() const;
    size_t size() const;
    void clear();
   

private:
    size_t m_capacity;
    T* m_array;
    size_t m_size;
    size_t m_head;
    size_t m_tail;

};
}//namespace
#include "./inl/block_queue.hxx"

#endif //BLOCK_QUEUE_HPP


