#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <cstddef> 

namespace cpp {

template <typename T>
class Queue
{
public:
    Queue(size_t a_size = 64);
    Queue(Queue const& a_source);
    Queue& operator=(Queue const& a_source);
    ~Queue();
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
#include "./inl/queue.hxx"

#endif